using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cs
{
    delegate double MyMath(double a, double b);
    class _02Delegate
    {
        static void Calculator(double a, double b, MyMath myMath)
        {
            Console.WriteLine(myMath(a, b));
        }

        static double plus(double a, double b) { return a + b; }
        static double minus(double a, double b) { return a - b; }
        static double multiply(double a, double b) { return a * b; }
        static void Main(string[] args)
        {
            Console.WriteLine("Delegate");
            MyMath Plus = new MyMath(plus);
            MyMath Minus = new MyMath(minus);
            MyMath Multiply = new MyMath(multiply);

            Calculator(11, 22, plus);
            Calculator(33, 22, minus);
            Calculator(11, 22, multiply);

        }
    }
}
