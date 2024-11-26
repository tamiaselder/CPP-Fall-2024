// ## Exercise 3 (Set)

// Write a program that receives a vector integer, removes all duplicates using a set, and prints the cleaned data set.


// ### Example of output

// ```
//   Numbers:
//   1 1 1 2 6 5 1 1 6

// Clean:
// 1 2 5 6
// ```

# include <set>
# include <vector>
# include <iostream>


int main (){
    std::vector<int> paul{1,2,2,3,5,6,8,899,6,6,5,4,3,2,2,2,3,4,5,6,7,6,4,3,332,4,4};
    std::set<int> clean_paul{};

    for (int num :paul){
        clean_paul.insert(num);
    }

    for (int num :clean_paul){  
        std::cout<< num << " ";
    }
    std::cout << std::endl;


    return 0;
}
