﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Windows.Media.Animation;
using System.Windows.Threading;

namespace WpfApp1
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        Random random = new Random();
        DispatcherTimer enemyTimer = new DispatcherTimer();
        DispatcherTimer targetTimer = new DispatcherTimer();
        bool humanCaptured = false;

        public MainWindow()
        {
            InitializeComponent();
            enemyTimer.Tick += EnemyTimer_Tick;
            enemyTimer.Interval = TimeSpan.FromSeconds(2);

            targetTimer.Tick += TargetTimer_Tick;
            targetTimer.Interval = TimeSpan.FromSeconds(.1);
        }

        private void TargetTimer_Tick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
            progressBar.Value += 1;
            if (progressBar.Value >= progressBar.Maximum)
            {
                EndTheGame();
            }
        }

        private void EndTheGame()
        {
            //throw new NotImplementedException();
            if (!playArea.Children.Contains(gameOverText)) {
                enemyTimer.Stop();
                targetTimer.Stop();
                humanCaptured = false;
                startButton.Visibility = Visibility.Visible;
                playArea.Children.Add(gameOverText);
            }
        }

        private void EnemyTimer_Tick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
            AddEnemy();
        }

        private void startButton_Click(object sender, RoutedEventArgs e)
        {
            //AddEnemy();
            StartGame();
        }

        private void StartGame()
        {
            //throw new NotImplementedException();
            human.IsHitTestVisible = true;
            humanCaptured = false;
            progressBar.Value = 0;
            startButton.Visibility = Visibility.Collapsed;
            playArea.Children.Clear();
            playArea.Children.Add(target);
            playArea.Children.Add(human);
            enemyTimer.Start();
            targetTimer.Start();

        }

        private void AddEnemy()
        {
            //throw new NotImplementedException();
            ContentControl enemy = new ContentControl();
            enemy.Template = Resources["EnemyTemplate"] as ControlTemplate;
            AnimateEnemy(enemy, 0, playArea.ActualWidth - 100, "(Canvas.Left)");
            AnimateEnemy(enemy, random.Next((int)playArea.ActualWidth - 100), random.Next((int)playArea.ActualHeight - 100), "(Canvas.Top)");
            playArea.Children.Add(enemy);

            enemy.MouseEnter += Enemy_MouseEnter;
        }

        private void Enemy_MouseEnter(object sender, MouseEventArgs e)
        {
            //throw new NotImplementedException();
            if (humanCaptured) {
                EndTheGame();
            }
        }

        private void AnimateEnemy(ContentControl enemy, double from, double to, string propertyToAnimate)
        {
            //throw new NotImplementedException();
            Storyboard storyboard = new Storyboard() { AutoReverse = true, RepeatBehavior = RepeatBehavior.Forever };
            DoubleAnimation animation = new DoubleAnimation()
            {
                From = from,
                To = to,
                Duration = new Duration(TimeSpan.FromSeconds(random.Next(4,6))),
            };
            Storyboard.SetTarget(animation, enemy);
            Storyboard.SetTargetProperty(animation, new PropertyPath(propertyToAnimate));
            storyboard.Children.Add(animation);
            storyboard.Begin();
        }

        private void human_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (enemyTimer.IsEnabled)
            {
                humanCaptured = true;
                human.IsHitTestVisible = false;
            }
        }

        private void target_MouseEnter(object sender, MouseEventArgs e)
        {
            if (targetTimer.IsEnabled && humanCaptured)
            {
                progressBar.Value = 0;
                Canvas.SetLeft(target, random.Next(100, (int)playArea.ActualWidth - 100));
                Canvas.SetTop(target, random.Next(100, (int)playArea.ActualHeight- 100));
                Canvas.SetLeft(human, random.Next(100, (int)playArea.ActualWidth - 100));
                Canvas.SetTop(human, random.Next(100, (int)playArea.ActualHeight - 100));
                humanCaptured = false;
                human.IsHitTestVisible = true;
            }
        }

        private void playArea_MouseMove(object sender, MouseEventArgs e)
        {
            if (humanCaptured) {
                Point pointPostion = e.GetPosition(null);
                Point relativePostion = grid.TransformToVisual(playArea).Transform(pointPostion);
                if ((Math.Abs(relativePostion.X - Canvas.GetLeft(human)) > human.ActualWidth + 3)
                    || (Math.Abs(relativePostion.Y - Canvas.GetTop(human)) > human.ActualHeight + 3))
                {
                    humanCaptured = false;
                    human.IsHitTestVisible = true;
                }
                else {
                    Canvas.SetLeft(human, relativePostion.X - human.ActualWidth / 2);
                    Canvas.SetTop(human, relativePostion.Y - human.ActualHeight / 2);
                }
            }
        }

        private void playArea_MouseLeave(object sender, MouseEventArgs e)
        {
            if (humanCaptured) {
                EndTheGame();
            }
        }
    }
}
