using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cs
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World\n");
            Console.WriteLine("a={0},b={1}", true, 123);
            int sum = 0;
            while (true) {
                Console.Write("숫자:");
                string line = Console.ReadLine();
                if (line.Equals("end")) {
                    break;
                }
                sum += int.Parse(line);
            }
            Console.WriteLine("합:={0}",sum);
        }
    }
}