using System;
using System.IO;
namespace Competitions
{
    public class Maths {
        
      public static void GeneratePowerSet(int[] array, int size)
        {
                 int total = 1 << size; //2^size
                 using (StreamWriter sw = new StreamWriter(@"output.txt"))
                 {
                    for (int i = 0; i < size; i++) 
                    {
                        for (int j = 0; j < size; j++) 
                        {
                            if (i && (1 << j)) 
                            {
                                sw.Write(array[j].ToString() + " ");               
                            }
                        }
                        sw.WriteLine();
                    }
                 }
        }
    }
}
