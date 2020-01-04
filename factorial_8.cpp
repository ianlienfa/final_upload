#include "factorial_8.h"

factorial::factorial()
{

}
string factorial::solve(string s)
{
    int index = 0 , count = 2,  prime_factor_sum = 0;
    vector<int> vec = stringtoVectorInt(s);
    int input_array[vec.size()],input_recover_array[vec.size()];
    string output_array[vec.size()],output_array_recover[vec.size()];
    string out = "";


    for(int i=0;i<vec.size();i++)
    {
        input_array[i] = vec[i];
        input_recover_array[i] = i;
    }
    //for(int i=0;i<vec.size();i++)
    QuickSort(input_array,input_recover_array,0,vec.size()-1);

    for(int i=0;i<vec.size();i++)
    {
        qDebug()<<input_array[i];
    }
    while(index<vec.size())
    {
        prime_factor_sum = prime_factor_sum + decomposition(count);
        while( prime_factor_sum > input_array[index])
        {
            output_array[index] = "N ";
            index = index + 1;
            if(index==vec.size())//Avoiding Segementation Fault
                break;
        }
        while( prime_factor_sum == input_array[index])
        {
            output_array[index] = to_string(count) + "! ";
            index = index + 1;
            if(index==vec.size())//Avoiding Segementation Fault
                break;
        }
        count = count + 1;
        //qDebug() << prime_factor_sum;
    }


   for(int i=0;i<vec.size();i++){
        output_array_recover[input_recover_array[i]] = output_array[i];
        //qDebug() << QString::fromStdString(output_array[i]);

    }
   for(int i=0;i<vec.size();i++){

        out = out + output_array_recover[i];
    }
   out = out.substr(0,out.length()-1);

   return out;
}
void factorial::swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int factorial::Partition(int *arr, int *recover, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            swap(&recover[i], &recover[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    swap(&recover[i], &recover[end]);
    return i;
}
void factorial::QuickSort(int *arr, int *recover,int front, int end){
    if (front < end) {
        int pivot = Partition(arr, recover,front, end);
        QuickSort(arr,recover,front, pivot - 1);
        QuickSort(arr,recover,pivot + 1, end);
    }
}
int factorial::decomposition(int in)
{
    int count_temp = 0; //單一數字的質因數分解個數
    for(unsigned int x=2;x<=int(sqrt(in));x++)
    {
        while(in%x==0)
        {
            count_temp = count_temp + 1;
            //qDebug() << in;
            in/=x;
        }
    }
    if(in!=1)
       count_temp = count_temp + 1;

    return count_temp;
}
