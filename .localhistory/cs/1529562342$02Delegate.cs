using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cs
{
    class _02Delegate
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Delegate Test");
            MyMath Plus = new MyMath(plus);
            MyMath Minus = new MyMath(minus);
            MyMath Multiply = new MyMath(multiply);

            Calculator(11, 22, plus);
            Calculator(33, 22, minus);
            Calculator(11, 22, multiply);

            MyMathT<int> Plus_int = new MyMathT<int> (plus);
            MyMathT<float> Minus_float = new MyMathT<float> (minus);
            MyMathT<double> Multiply_double = new MyMathT<double>(multiply);

            Calculator(11, 22, plus);
            Calculator(3.3f, 2.2f, minus);
            Calculator(11.3, 22.7, multiply);
        }
        delegate T MyMathT<T>(T a, T b);
        static void CalculatorT<T>(T a, T b, MyMathT<T> myMath)
        {
            Console.WriteLine(myMath(a, b));
        }
        static int plus(int a, int b) { return a + b; }
        static float minus(float a, float b) { return a - b; }
        //static double multiply(double a, double b) { return a * b; }

        delegate double MyMath(double a, double b);
        static void Calculator(double a, double b, MyMath myMath)
        {
            Console.WriteLine(myMath(a, b));
        }

        static double plus(double a, double b) { return a + b; }
        static double minus(double a, double b) { return a - b; }
        static double multiply(double a, double b) { return a * b; }
    }
}
