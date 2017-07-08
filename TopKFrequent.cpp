// Code to return the top k frequent elements.

#include <iostream>
#include <algorithm>

using namespace std;

struct Item
{
  int value;
  int frequency;
};

bool compare(Item a, Item b)
{
  return a.frequency > b.frequency;
}

void TopKValues(int *values, int n, int k)
{
  Item *items;
  int index = 1;
  
  sort(values, values + n);
  items = (Item *)malloc(n * sizeof(Item));
  
  items[0].value = values[0];
  items[0].frequency = 1;
  for(int i = 1; i < n; ++i)
  {
    if(values[i] == values[i - 1])
    {
      items[index - 1].frequency++;
    }
    else
    {
      items[index].value = values[i];
      items[index].frequency = 1;
      index++;
    }
  }
  
  sort(items, items + index, compare);
  for(int i = 0; i < k && i < index; ++i)
  {
    cout << items[i].value << " ";
  }
}

int main()
{
  int n, k;
  int *values;
  
  cin >> n >> k;
  values = (int *)malloc(n * sizeof(int));
  for(int i = 0; i < n; ++i)
  {    
    cin >> values[i]; 
  }
  
  TopKValues(values, n, k);
  
  return 0;
}