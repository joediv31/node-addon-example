#include <node.h>
#include <v8.h>
#include "myMath.hpp"
#include <string>

using namespace v8;

Handle<Value> Compute(const Arguments& args){
    
    HandleScope scope;

    Local<Value> v = args[1];
    
    //make sure args is an array
    if(v->IsArray()){
        
        Local<Array> arr = Local<Array>::Cast(v);
        
        int length = 0;
        
        length = arr->Get(String::New("length"))->ToObject()->Uint32Value();
        
        std::vector<double> myArgs(length);
        
        //convert the v8::Array to a std::vector<double>
        for(int i=0; i<length; i++)
        {
            //check to make sure each value is a valid number, if not throw exception
            if(arr->Get(Number::New(i))->IsNumber())
                myArgs[i] = arr->Get(Number::New(i))->ToObject()->NumberValue();
            else{
                ThrowException(Exception::TypeError(String::New("Invalid values in array.")));
                return scope.Close(Undefined());
            }
        }
        
        //use our new std::vector in our external library
        String::Utf8Value inputString(args[0]->ToString());
        
        std::string arg1 = *inputString;
        
        if(!(arg1 == "add" || arg1 == "subtract" || arg1 == "multiply"))
        {
            ThrowException(Exception::TypeError(String::New("Arg1 must be 'add', 'subtract', 'multiply'")));
            return scope.Close(Undefined());
        }
        else{
            
            myMath myMathObj;
            double result = 0;
            
            if(arg1 == "add")
                result = myMathObj.add(myArgs);
            else if(arg1 == "subtract")
                result = myMathObj.subtract(myArgs);
            else if(arg1 == "multiply")
                result = myMathObj.multiply(myArgs);
            
            //convert result back to v8 number object and return it
            return scope.Close(Number::New(result));
        }
    }
    else{
        //throw exception
        ThrowException(Exception::TypeError(String::New("2nd argument must be an array.")));
        return scope.Close(Undefined());
    }
    
}

void init(Handle<Object> exports){
    
    exports->Set(String::NewSymbol("compute"), FunctionTemplate::New(Compute)->GetFunction());

}

NODE_MODULE(fastMath, init)


