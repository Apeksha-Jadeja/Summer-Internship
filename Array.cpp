// Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

#pragma region easy

void q1() {
    int a[10];
    cout << "enter 10 elements\n";
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for (int i : a) {
        cout << i << "\n";
    }

}

void q2(int num, int size) {
     int* a,c=0;
     a=new int[size];
     for (int i = 0; i < size; i++) {
         cin >> a[i];
     }

     for (int i = 0; i < size; i++) {
         if (num == a[i]) {
             cout<< "true";
             c = 1;
             break;
         }
     }
     if (c == 0) { cout << "False"; }
}


void q3(int size) {
    int* array,max=0,min=0;
    array = new int[size];
    cout << "enter elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    min = array[0];
    max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        else if (array[i] < min) {
            min = array[i];
        }
    }
    cout << "MAX :" << max << "\n";
    cout << "MIN: " << min << "\n";
}

void q4(int size) {
    int* a, * b;
    a = new int[size];
    b = new int[size];
    cout << "enter elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < size; i++) {
        b[i] = a[size - (i+1)];
    }
    for (int i = 0; i < size; i++) {
        cout << b[i] << " ";
    }
}

void q5(int size) {
    int* a,temp=0;
    a = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size - 1; i++)  {
             if (a[i] > a[i+1]) {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
           
    }

    for (int i = 0; i < size; i++) {
        cout << a[i]<<" ";
    }
}

void q6(int num,int size) {
    int* a, temp = 0;
    a = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    //sort
   
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size - 1; i++) {
            if (a[i] > a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }

    }
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    //find 
    int x = size - (num);
    cout << num << "rd largest: " << a[x]<<"\n";
    cout << num << "rd smallest: " << a[num-1];
        
}

void q7() {
    
    array <int,15> a{ 1,1,1,2,87,65,78,36,1 };
    int occ = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 1) {
            occ++;
        }
    }
    cout << "1 has occured :" << occ << "times";
}

void q8() {
    int zero=0, one=0, two=0;
    int arr[] = { 0,0,1,2,0,1,2,1,2,1,0,1,2 };

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : arr) {
        if (i == 0) {
            zero++;
        }
        else if (i == 1) {
            one++;
        }
        else {
            two++;
        }
    }
    int i = 0;
    while (zero > 0) {
        arr[i++] = 0;
        zero--;
        
    }
    while (one > 0) {
        arr[i++] = 1;
        one--;
    }
    while (two > 0) {
        arr[i++] = 2;
        two--;
    }

    for (int k : arr) {
        cout << k << " ";
    }
}

void q9(int size) {

    int* array, max = 0, min = 0;
    array = new int[size];
    cout << "enter elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    min = array[0];
    max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        else if (array[i] < min) {
            min = array[i];
        }
    }
    cout << "MAX :" << max << "\n";
    cout << "MIN: " << min << "\n";
    cout << "Difference between max and min:" << max - min;
}

void q10() {
    int arr[5] = { -8,8,9,4,-1 };
    int j = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
    for (int k : arr) {
        cout << k << " ";
    }
}

#pragma endregion 


#pragma region intermediate

void show(int a[], int arraysize)
{
    for (int i = 0; i < arraysize; ++i)
        cout << a[i] << ",";
}

void Q1() {
    //UNION INTERSECTION
    int arr1[] = { 15,4,6,11,78,-6,12,87,58 };
    int arr2[] = { 4,65,78,66,12,11,13,47,6 };

    vector<int>intersection;
    vector<int>unions;
  
    for (int i = 0; i < 9; i++) {
        unions.push_back(arr1[i]);
        for (int j = 0; j < 9; j++) {
            if (arr1[i] == arr2[j]) {
                intersection.push_back(arr2[j]);
            
            }
        }
    }

    for (auto i = intersection.cbegin(); i != intersection.cend(); ++i) {
        cout << *i << " ";
        

    }
    cout << endl;

    int x;
    sort(arr1, arr1 + 9);
    sort(arr2,arr2+9);

        for (int j : arr2) {
            x = binary_search(arr1, arr1+9, j);
                
            if (x==0) {
                unions.push_back(j);
            }
        }
 

        cout << endl; cout << endl; cout << endl;
    for (auto i = unions.cbegin(); i != unions.cend(); ++i) {
        cout << *i << " ";


    }
}

void Q2() {
    int arr[] = { 1,2,3,4,5 };
    int n = 5;
    int  last = arr[n - 1];

    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
    
    for (int i : arr) {
        cout << i << " ";
    }
}


#pragma endregion
void main()
{
#pragma region easy_ans
    //q1();
    //q2(7,5);
    //q3(5);
    //q4(5);
    //q5(5);
    //q6(3, 5);
    //q7();
   // q8();
   // q9(5);
    //q10();
#pragma endregion

#pragma region intermediate_ans
    //Q1();
    //Q2();
#pragma endregion

}


