#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

enum operations{

  ADD,
  AND

};

class CPU{

  private:

    int PC; 
    int AC;
    operations insrt;//this is a holding register for current instruction
    vector<int> data; //holding the current data in CPU memory
    bool run_bit = true;
    
    /////

    void execute(operations& type, int* data){
      


      if (type == ADD && this->data.size() >> 1){ // is the ADD operation? ok then I'll add them all
         
          AC = accumulate(this->data.begin(), this->data.end(), 0);
          
          printf("The result is: %i\n", AC);
          
          //stopping 
          run_bit = false;

      }else if (type == AND){ //is the AND operation? ok then I'll add a number
            
          this->data.push_back(data[PC]);
          

      }else{ //DATA has to have more than one word

        printf("The DATA has only one word. Please add two or more.\n");

      }//else if


    }//execute

  //////

  public:

    void interpret(operations* operations, int* data, int startAddress){

      PC = startAddress;

      while(run_bit){

        insrt = operations[PC]; //see the operation that I have to do 

        execute(insrt, data);

        PC++; // go to the next operation and data

      }//while

    }//interpert

}; //class CPU


int main (int argc, char *argv[]) {
  
  CPU myCPU;

  int myData[] = {3, 5, 8, 10};
  operations ops[] = {AND, AND, AND, AND, ADD}; //the AND is always equivalent to how many data has in myData
                                                //could do a for statement that adds more AND operation too! 

  myCPU.interpret(ops, myData, 0);

  return 0;
}
