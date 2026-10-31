#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int add_number(vector<int>& array){
    int n;
    cout << "Enter number to be add: ";
    cin >> n;
    array.push_back(n);
}

void display_array(vector<int>& array){
    for(auto val:array){
        cout << val << " ";
    }
    cout << "\n";
}

void calculate_statistics(vector<int>& array){
    if(array.empty()){
        cout << "array is empty!" << endl;
        return;
    }
    cout << "Number of elements in array: " << array.size() << "\n";
    cout << "Maximum element: " << *max_element(array.begin(), array.end()) << "\n";
    cout << "Minimum Element: " << *min_element(array.begin(), array.end()) << "\n";

    cout << "Sum of all elements: " << accumulate(array.begin(), array.end(), 0LL) << "\n";
    double avg = static_cast<double>((accumulate(array.begin(), array.end(), 0LL))/array.size());
    cout << "Average of elements: " << avg << "\n";

}

void sort_array(vector<int>& array){
    sort(array.begin(), array.end());

}

void search_element(vector<int>& array){
    if(array.empty()){
        cout << "array is empty!" << endl;
        return;
    }
    int x;
    cout << "Enter the element to search: ";
    cin >> x;

    sort_array(array);
    bool found = binary_search(array.begin(), array.end(), x);

    if(found){
        cout << x << " found in the collection.\n";
    }
    else{
        cout << x <<" not found.\n";
    }
}

void remove_occurence(vector<int>& array){
    if(array.empty()){
        cout << "Array is empty!\n";
        return;
    }

    int x;
    cout << "Enter the number to remove its occurance from the collection: ";
    cin >> x;

    auto it = find(array.begin(), array.end(), x);

    if(it != array.end()){
        array.erase(it);
        cout << x << " removed successfully." << endl;
    }
    else{
        cout << x << " not found.\n";
    }

}


int main(){
    int choice;
    vector<int>array;
    do{
        cout << "============Command-Driven Data Analyzer============" << endl;
        cout << "1. Add an integer" << endl;
        cout << "2. Display Collection" << endl;
        cout << "3. Calculate statistics" << endl;
        cout << "4. Search for a value" << endl;
        cout << "5. Remove an occurrence" << endl;
        cout << "6. Sort an array" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;
        

        switch(choice){
            case 1:
            {
                add_number(array);
                break;
            }
            case 2:
            {
                display_array(array);
                break;
            }
            case 3:
            {
                calculate_statistics(array);
                break;
            }
            case 4:
            {
                search_element(array);
                break;
            }
            case 5:
            {
                remove_occurence(array);
                break;
            }
            case 6:
            {
                sort_array(array);
                break;
            }
            case 0:
            {
                cout << "Exiting the program!";
                return 0;
            }
            default:
            {
                cout << "Invalid Choice!\nSelect the choice between 1 to 6 and 0 to exit!";
                break;
            }
        }

    }while(choice!=0);
    return 0;
}