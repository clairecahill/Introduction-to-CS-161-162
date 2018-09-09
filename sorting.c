#include <stdio.h>
#include <stdlib.h>

typedef struct timeval time;
void print_array(int *, int);
void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void selection_sort(int *, int);
void insertion_sort(int *, int);
void bubble_sort(int *, int);
void fill_array(int **, int *);
void add_num(int **, int *, int);
void test();

int main(){
   int *nums=NULL;
   int size=0;
   time stop, start; 


   fill_array(&nums, &size);
   print_array(nums, size);

   //Time the function here
   gettimeofday(&start, NULL);
   
   //bubble_sort(nums, size);
   //insertion_sort(nums, size);
   merge_sort(nums, 0, size-1);
   //selection_sort(nums, size);

   gettimeofday(&stop, NULL);

   printf("MicroSeconds: %d\n", stop.tv_usec-start.tv_usec);
   printf("Seconds: %d\n", stop.tv_sec-start.tv_sec);

   print_array(nums, size);
   free(nums);

   return 0;
}

/*************************************************
 * Description: This prints the contents of an array
 * Params: array of integers and size of the array
 * Returns: none
 * Post-conditions: none
 * Pre-conditions: size is accurate number of 
 *                 elements in the array >=0
 * **********************************************/
void print_array(int *nums, int size){
   int i;

   printf("The array elements are:\n");
   for(i=0; i<size; i++)
      printf("%d\t", nums[i]);
   printf("\n\n");
}

/*************************************************
 * Description: merges two subarrays into one sorted
 * array by comparing the first elements of each subarray
 * and placing the lowest onto the new merged array. This 
 * repeats for all the elements of both arrays until
 * one sorted array remains
 * Parameters: pointer to an array of ints, int left 
 * to hold the size of the left subarray and int right
 * to hold the size of the right subarray, and an int 
 * mid to mark the value where the array is split in two
 * Return: none
 * Pre-Conditions: the pointer must point to a valid 
 * array of integers and the merge_sort function must
 * be called twice previously in order to create two
 * subarrays to merge
 * Post-Conditions: num points to a sorted array of 
 * ints from least to greatest
 * ***********************************************/

void merge(int *nums, int left, int mid, int right){
   int i, j, lower_half, upper_half;
   int temp[(right-left)+1];

   lower_half=left;  //What is this for?
   upper_half=mid+1;  //What is this for?
   
   //What does this loop do?
   for(i=0; (lower_half<=mid)&&(upper_half<=right); i++){
      //What does this condition do?
      if(nums[lower_half]<=nums[upper_half]){
	 temp[i]=nums[lower_half];
	 lower_half++;
      }
      //What does this condition do?
      else{
	 temp[i]=nums[upper_half];
	 upper_half++;
      }
   }

   //What does this condition and loop do?
   if(lower_half>mid)
      for(j=upper_half;j<=right;j++, i++)
	 temp[i]=nums[j];
   //What does this else and loop do?
   else
      for(j=lower_half;j<=mid;j++, i++)
	 temp[i]=nums[j];

   //What does this loop do?
   for(j=0,i=left;i<=right;i++,j++)
      nums[i]=temp[j];
}

/*************************************************
 * Description: This function uses recursion to split
 * the orginial array into subarrays. It divides the 
 * array until there is only one element, then calls
 * merge in order to merge and sort the arrays. The
 * subarrays merge into one another until it is the
 * same size as the original array
 * Parameters: pointer to an array of ints, int left
 * to hold the size of left part of the array, int
 * right to hold the size of the right part of the array
 * Return: none
 * Pre-Conditions: nums must point to a valid array of ints
 * and left and right must be valid ints
 * Post-Conditions: original array of ints is sorted
 * from least to greatest
 * ***********************************************/

void merge_sort(int *nums, int left, int right) {
   int mid; 
   if(left<right) {
      mid=(right+left)/2;
      merge_sort(nums, left, mid);  //what does this call do?
      merge_sort(nums, mid+1, right); //what does this call do?
      merge(nums, left, mid, right);  //what does this call do?
   }
}

/*************************************************
 * Description: This algorithm works by remembering
 * the smallest value in the "unsorted" portion of the
 * list and moves it to the "sorted" portion. It stores
 * the minimum value and swaps it with the current value 
 * in the unsorted portion
 * Parameters: pointer to an array of ints, int size of array
 * Return: none
 * Pre-Conditions: nums must point to a valid pointer of
 * integers and size must be a valid number greater than 0
 * Post-Conditions: nums points to a list of sorted ints
 * from least to greatest
 * ***********************************************/

void selection_sort(int *nums, int size) {
   int i, j;
   int temp, min;

   //What does this loop do?
   for(i=0; i<size-1; i++) {
      min=i;
      //What does this loop do?
      for(j=i; j<size; j++)
	 if(nums[j]<nums[min]) 
	    min=j;
      //What elements are being swaped?
      temp=nums[i];
      nums[i]=nums[min];
      nums[min]=temp;
   }
}

/*************************************************
 * Description: This algorithm uses a temp int to 
 * store the value of the array that will be inserted
 * into its correct position. The value is checked 
 * with all the previous values in the array and if
 * it is smaller, then the two positions are swapped
 * so the values are sorted from least to greatest
 * Parameters: pointer to array of ints, int size of array
 * Returns: none
 * Pre-Conditions: nums must hold a valid array of ints
 * and int size must be greater than 0
 * Post-Conditions: nums points to an array of ints
 * sorted from least to greatest
 * ***********************************************/

void insertion_sort(int *nums, int size) {
   int i, j;
   int temp;

   //What does this loop do?
   for(i=0; i<size; i++) {
      temp=nums[i]; 
      //What does this loop do?
      for(j=i; j>0 && nums[j-1]>temp; j--) 
	 nums[j]=nums[j-1];
      //What does this statment do?
      nums[j]=temp;
   }
}

/*************************************************
 * Description: This algorithm uses two for loops 
 * to loop through the array enough times to sort 
 * the elements. Two side by side elements are compared
 * in the list, and if the first is greater than the 
 * second, then the elements are swapped. 
 * Parameters: array pointer to ints and int size of array
 * Returns: none
 * Pre-Conditions: nums must point to a valid array of 
 * ints and size must be an int greater than 0
 * Post-Conditions: nums is altered and sorted from least
 * to greatest.
 * ***********************************************/

void bubble_sort(int *nums, int size) {
   int i, j;
   int temp;

   //What does this loop do?
   for(i=0; i<size; i++) {
      //What does this loop do?
      for(j=0; j<size-i-1; j++) {
	 if(nums[j]>nums[j+1]) {
	    temp=nums[j];
	    nums[j]=nums[j+1];
	    nums[j+1]=temp;
	 }
      }
   }
}

/*************************************************
 * Description: This adds an element to the array
 * and sets the contents to num
 * Params: address of array pointer to ints and 
 *         address of size of the array
 * Returns: none
 * Post-conditions: size is increased by one and
 * nums points to new array with one more element
 * where the contents are the same with num at the end
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void add_num(int **nums, int *size, int num){
   int *old_nums, i;

   *size+=1;
   old_nums=*nums;
   *nums=(int *) malloc(sizeof(int)*(*size));

   for(i=0; i<*size-1; i++)
      (*nums)[i]=old_nums[i];
   (*nums)[*size-1]=num;

   free(old_nums);
}

/*************************************************
 * Description: This fills an array with contents
 * from a file
 * Params: address of array pointer to ints and 
 *         address of size of the array
 * Returns: none
 * Post-conditions: array pointer is pointing to
 * valid array of integers or NULL and size has
 * a positive integer
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void fill_array(int **nums, int *size) {
   FILE *fptr;
   char filename[20], num[10];

   printf("Enter the filename: ");
   scanf("%s",filename);
   fptr=fopen(filename,"r");

   while(fscanf(fptr,"%s", num)!=EOF){
      add_num(nums, size, atoi(num));
   }

   fclose(fptr);
}

