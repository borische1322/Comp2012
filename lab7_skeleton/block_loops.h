#ifdef BLOCK_LOOPS

#define for(X) throw logic_error("You are not allowed to use for loop in this lab."); \

#define while(X) throw logic_error("You are not allowed to use while loop in this lab."); \

#endif