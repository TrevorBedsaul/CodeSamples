#include <iostream>
#include <cstdlib>

using namespace std;

int sum(int arr[]) {
  return arr[0] + arr[1];
}

int main() {
  int arr[] = {3,5};
  cout << sum(arr) << endl;
  
}
