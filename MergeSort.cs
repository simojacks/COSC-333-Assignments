using System; 
public class MergeSortExample 
{ 
public static void MergeSort(int[] array, int left, int right) 
{ 
if (left < right) 
{ 
int middle = left + (right - left) / 2; 
MergeSort(array, left, middle); 
MergeSort(array, middle + 1, right); 
Merge(array, left, middle, right); 
} 
} 
public static void Merge(int[] array, int left, int middle, int 
right) 
{ 
int n1 = middle - left + 1; 
int n2 = right - middle; 
int[] leftArray = new int[n1]; 
int[] rightArray = new int[n2]; 
Array.Copy(array, left, leftArray, 0, n1); 
Array.Copy(array, middle + 1, rightArray, 0, n2); 
int i = 0, j = 0; 
int k = left; 
        while (i < n1 && j < n2) 
        { 
            if (leftArray[i] <= rightArray[j]) 
            { 
                array[k] = leftArray[i]; 
                i++; 
            } 
            else 
            { 
                array[k] = rightArray[j]; 
                j++; 
            } 
            k++; 
        } 
 
        while (i < n1) 
        { 
            array[k] = leftArray[i]; 
            i++; 
            k++; 
        } 
 
        while (j < n2) 
        { 
            array[k] = rightArray[j]; 
            j++; 
            k++; 
        } 
    } 
 
    public static void Main() 
    { 
        int[] array = { 38, 27, 43, 3, 9, 82, 10 }; 
        Console.WriteLine("Original array:"); 
        Console.WriteLine(string.Join(", ", array)); 
 
        MergeSort(array, 0, array.Length - 1); 
 
        Console.WriteLine("Sorted array:"); 
Console.WriteLine(string.Join(", ", array)); 
} 
} 