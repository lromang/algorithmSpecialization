#include <stdio.h>
#include <stdlib.h>

int brackets(char *, int);

int main(){
  char*  string;
  size_t size;
  int    i, test;
  // Init variables
  size   = 100000;
  string = malloc(size*sizeof(char));
  getline(&string, &size, stdin);
  for(i = 0; string[i] != '\0'; i++);
  test   = brackets(string, i - 1);
  if(test == -1){
    printf("%s", "Success");
  }else{
    printf("%d", test);
  }
  return 0;
}

int brackets(char* string, int n){
  int i, top;
  char *stack, *leftIndex;
  // Allocate space for stack.
  stack      = (char*)malloc(n*sizeof(char));
  leftIndex  = (char*)malloc(n*sizeof(char));
  top        = -1;
  // Loop
  for(i = 0; i < n; i++){
    if(string[i] == '{' || string[i] == '[' || string[i] == '('){
      top ++;
      stack[top]     = string[i];
      leftIndex[top] = i + 1;
    }else if((top == -1) && (string[i] == '}' || string[i] == ']' || string[i] == ')')){
      return i + 1;
    }else if((string[i] == '}' && stack[top] != '{') ||
             (string[i] == ')' && stack[top] != '(') ||
             (string[i] == ']' && stack[top] != '[')) {
      return i + 1;
    }else if(string[i] == '}' || string[i] == ']' || string[i] == ')'){
      top --;
    }
  }
  return top == -1? top: leftIndex[top];
}
