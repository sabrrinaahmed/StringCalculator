#include <iostream>
#include <string>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    int intDigit = digit - '0';
    if (intDigit < 0 || intDigit > 9)
        throw std::invalid_argument("Invalid Argument.");
    return intDigit;
}

char decimal_to_digit(unsigned int decimal) {
    if (decimal > 9)
        throw std::invalid_argument("Invalid Argument.");
    char charDecimal = decimal + '0';
    return charDecimal;
}

string trim_leading_zeros(string num) {
    if (num[0] == '-'){
        for(int i = 0; i < num.size(); i++){
            if(i == num.size() - 1 && num[i] == '0'){
                num = "0";
            } else if(num[i] == '0'){
                num.erase(i,1);
                i--;
            } else if (num[i] == '-'){
                continue;
            } else{
                break;
            }  
        }
    } else {
        for(int i = 0; i < num.size(); i++){
            if(i == num.size() - 1 && num[i] == '0'){
                num == "0";
            } else if(num[i] == '0'){
                num.erase(i,1);
                i--;
            } else{
                break;
            }
        }
        
    }

    return num;
}

string add(string lhs, string rhs) {
    string result = "";
    string helper;
    int sum = 0;
    int carry = 0;
    int counter = 1;

    if (lhs[0] != '-' && rhs[0] != '-'){
        if(lhs.size() < rhs.size())
            swap(lhs,rhs);
        int j = rhs.length() - 1;
        for(int i = lhs.length() - 1; i < lhs.length(); i--){
            sum = (lhs[i]-'0') + (rhs[j]-'0') + carry;
            if(carry == 1)
                carry--;
            if(sum > 9){
                carry++;
                sum -= 10;
            }
            helper = std::to_string(sum);
            result.insert(0,helper);
            if (i == 0 && j == 0 && carry == 1){
                result.insert(0,"1");
            }
            if (j == 0 && i != 0){
                i--;
                for(int k = i; i >= 0; k--){
                    sum = lhs[k] - '0' + carry;
                    if(sum > 9){
                        carry = 1;
                        sum -= 10;
                    } else {
                        carry = 0;   
                    }
                    helper = std::to_string(sum);
                    result.insert(0,helper);
                    i--;
                    if (k == 0 && carry == 1){
                        result.insert(0,"1");
                    }  
                } 
                break;
            }
            j--;
        }
    } else if (lhs[0] == '-' && rhs[0] != '-'){

        lhs.erase(0,1);

        //std::stringstream strFirst(lhs);
        double dblFirst = 0;
        //strFirst >> intFirst;

        //std::stringstream strSecond(rhs);
        double dblSecond = 0;
        //strSecond >> intSecond;
        dblFirst = stod(lhs);
        dblSecond = stod(rhs);


        if(dblFirst < dblSecond)
            swap(lhs,rhs);

        int j = rhs.length() - 1;
        for(int i = lhs.length() - 1; i < lhs.length(); i--){
            if(lhs.size() > 1 && ((lhs[i]-'0') - (rhs[j]-'0')) < 0){
                sum = (10 + lhs[i]-'0') - (rhs[j]-'0') + carry;
                if(lhs[i-1] == '0'){
                    while(counter >= 0){
                        if(lhs[i-counter] != '0'){
                            lhs[i-counter] -= 1;
                            counter = -1;
                        } else {
                            lhs[i-counter] = '9';
                            counter++;
                        }
                    }
                    counter = 1;
                    
                } else {
                    lhs[i-1] -= 1;
                }
            } else {
                sum = (lhs[i]-'0') - (rhs[j]-'0') + carry;
            }
            if(carry == 1)
                carry--;
            if(sum > 9){
                carry++;
                sum -= 10;
            }
            helper = std::to_string(sum);
            result.insert(0,helper);

            if (i == 0 && j == 0 && carry == 1){
                result.insert(0,"1");
            }
            if (j == 0 && i != 0){
                i--;
                for(int k = i; i >= 0; k--){
                    if(lhs[k] == '0'){
                        break;
                    }
                    sum = lhs[k] - '0' + carry;
                    if(sum > 9){
                        carry = 1;
                        sum -= 10;
                    } else {
                        carry = 0;   
                    }
                    helper = std::to_string(sum);
                    result.insert(0,helper);
                    i--;
                    if (k == 0 && carry == 1){
                        result.insert(0,"1");
                    }  
                } 
                break;
            }
            j--;
        }

        if(dblFirst > dblSecond){
            result.insert(0, "-");
        } else if (result[0] == '-'){
            result.erase(0,1);
        }
        if (result[0] == '0'){
            result = trim_leading_zeros(result);
        } else if (result[0] == '-' && result[1] == '0'){
            result = trim_leading_zeros(result);
        }

    } else if (rhs[0] == '-' && lhs[0] != '-'){

        rhs.erase(0,1);

        //std::stringstream strFirst(lhs);
        double dblFirst = 0;
        //strFirst >> intFirst;

        //std::stringstream strSecond(rhs);
        double dblSecond = 0;
        //strSecond >> intSecond;
        dblFirst = stod(lhs);
        dblSecond = stod(rhs);


        if(dblFirst < dblSecond)
            swap(lhs,rhs);

        int j = rhs.length() - 1;
        for(int i = lhs.length() - 1; i < lhs.length(); i--){
            if(lhs.size() > 1 && ((lhs[i]-'0') - (rhs[j]-'0')) < 0){
                sum = (10 + lhs[i]-'0') - (rhs[j]-'0') + carry;
                if(lhs[i-1] == '0'){
                    while(counter >= 0){
                        if(lhs[i-counter] != '0'){
                            lhs[i-counter] -= 1;
                            counter = -1;
                        } else {
                            lhs[i-counter] = '9';
                            counter++;
                        }
                    }
                    counter = 1;
                    
                } else {
                    lhs[i-1] -= 1;
                }
            } else {
                sum = (lhs[i]-'0') - (rhs[j]-'0') + carry;
            }
            if(carry == 1)
                carry--;
            if(sum > 9){
                carry++;
                sum -= 10;
            }

            helper = std::to_string(sum);
            result.insert(0,helper);

            if (i == 0 && j == 0 && carry == 1){
                result.insert(0,"1");
            }
            if (j == 0 && i != 0){
                i--;
                for(int k = i; i >= 0; k--){
                    if(lhs[k] == '0'){
                        break;
                    }
                    sum = lhs[k] - '0' + carry;
                    if(sum > 9){
                        carry = 1;
                        sum -= 10;
                    } else {
                        carry = 0;   
                    }

                    helper = std::to_string(sum);
                    result.insert(0,helper);
                    i--;

                    if (k == 0 && carry == 1){
                        result.insert(0,"1");
                    }  
                } 
                break;
            }
            j--;

        }

        if(dblFirst < dblSecond){
            result.insert(0, "-");
        } else if (result[0] == '-'){
            result.erase(0,1);
        }
        if (result[0] == '0'){
            result = trim_leading_zeros(result);
        } else if (result[0] == '-' && result[1] == '0'){
            result = trim_leading_zeros(result);
        }

    } else if (lhs[0] == '-' && rhs[0] == '-'){
        if(lhs.size() < rhs.size())
            swap(lhs,rhs);

        lhs.erase(0,1);
        rhs.erase(0,1);

        int j = rhs.length() - 1;
        for(int i = lhs.length() - 1; i < lhs.length(); i--){
            sum = (lhs[i]-'0') + (rhs[j]-'0') + carry;
            if(carry == 1)
                carry--;
            if(sum > 9){
                carry++;
                sum -= 10;
            }

            helper = std::to_string(sum);
            result.insert(0,helper);

            if (i == 0 && j == 0 && carry == 1){
                result.insert(0, "1");
            }
            if (i != 0 && j == 0){
                i--;
                for(int k = i; i >= 0; k--){
                    sum = lhs[k] - '0' + carry;
                    if(sum > 9){
                        carry = 1;
                        sum -= 10;
                    } else {
                        carry = 0;   
                    }

                    helper = std::to_string(sum);
                    result.insert(0,helper);
                    i--;

                    if (k == 0 && carry == 1){
                        result.insert(0,"1");
                    }
                }
                break;
            }
            j--;
        }
        result.insert(0,"-");
    }

    return result;
}

string subtract(string lhs, string rhs) {
    string result = "";
    string helper;
    int sum = 0;
    int carry = 0;
    int counter = 1;

    if (lhs[0] != '-' && rhs[0] != '-'){

        //std::stringstream strFirst(lhs);
        double dblFirst = 0;
        //strFirst >> intFirst;

        //std::stringstream strSecond(rhs);
        double dblSecond = 0;
        //strSecond >> intSecond;
        dblFirst = stod(lhs);
        dblSecond = stod(rhs);


        if(dblFirst < dblSecond)
            swap(lhs,rhs);

        int j = rhs.length() - 1;
        for(int i = lhs.length() - 1; i < lhs.length(); i--){
            if(lhs.size() > 1 && ((lhs[i]-'0') - (rhs[j]-'0')) < 0){
                sum = (10 + lhs[i]-'0') - (rhs[j]-'0');
                if(lhs[i-1] == '0'){
                    while(counter >= 0){
                        if(lhs[i-counter] != '0'){
                            lhs[i-counter] -= 1;
                            counter = -1;
                        } else {
                            lhs[i-counter] = '9';
                            counter++;
                        }
                    }
                    counter = 1;
                    
                } else {
                    lhs[i-1] -= 1;
                }

            } else {
                sum = (lhs[i]-'0') - (rhs[j]-'0');
            }
            helper = std::to_string(sum);
            result.insert(0,helper);

            if (i == 0 && j == 0 && carry == 1){
                result.insert(0,"1");
            }
            if (j == 0 && i != 0){
                i--;
                for(int k = i; i >= 0; k--){
                    /*if(lhs[k] == '0'){
                        break;
                    }*/
                    sum = lhs[k] - '0' + carry;
                    if(sum > 9){
                        carry = 1;
                        sum -= 10;
                    } else {
                        carry = 0;   
                    }
                    helper = std::to_string(sum);
                    result.insert(0,helper);
                    i--;
                    if (k == 0 && carry == 1){
                        result.insert(0,"1");
                    }  
                } 
                break;
            }
            j--;
        }
        if(dblFirst < dblSecond){
            result.insert(0, "-");
        } else if (result[0] == '-'){
            result.erase(0,1);
        }
        if (result[0] == '0'){
            result = trim_leading_zeros(result);
        } else if (result[0] == '-' && result[1] == '0'){
            result = trim_leading_zeros(result);
        }
    }
    if (lhs[0] == '-' && rhs[0] == '-'){
        lhs.erase(0,1);
        rhs.erase(0,1);

        //std::stringstream strFirst(lhs);
        double dblFirst = 0;
        //strFirst >> intFirst;

        //std::stringstream strSecond(rhs);
        double dblSecond = 0;
        //strSecond >> intSecond;
        dblFirst = stod(lhs);
        dblSecond = stod(rhs);


        if(dblFirst < dblSecond)
            swap(lhs,rhs);

        int j = rhs.length() - 1;
        for(int i = lhs.length() - 1; i < lhs.length(); i--){
            if(lhs.size() > 1 && ((lhs[i]-'0') - (rhs[j]-'0')) < 0){
                sum = (10 + lhs[i]-'0') - (rhs[j]-'0');
                if(lhs[i-1] == '0'){
                    while(counter >= 0){
                        if(lhs[i-counter] != '0'){
                            lhs[i-counter] -= 1;
                            counter = -1;
                        } else {
                            lhs[i-counter] = '9';
                            counter++;
                        }
                    }
                    counter = 1;
                    
                } else {
                    lhs[i-1] -= 1;
                }
            } else {
                sum = (lhs[i]-'0') - (rhs[j]-'0');
            }
            helper = std::to_string(sum);
            result.insert(0,helper);

            if (j == 0 && i != 0){
                i--;
                for(int k = i; i >= 0; k--){
                    if(lhs[k] == '0'){
                        break;
                    }
                    sum = lhs[k] - '0' + carry;
                    if(sum > 9){
                        carry = 1;
                        sum -= 10;
                    } else {
                        carry = 0;   
                    }
                    helper = std::to_string(sum);
                    result.insert(0,helper);
                    i--;
                    if (k == 0 && carry == 1){
                        result.insert(0,"1");
                    }  
                } 
                break;
            }
            j--;
        }

        if(dblFirst > dblSecond){
            result.insert(0, "-");
        } else if (result[0] == '-'){
            result.erase(0,1);
        }
        if (result[0] == '0'){
            result = trim_leading_zeros(result);
        } else if (result[0] == '-' && result[1] == '0'){
            result = trim_leading_zeros(result);
        }
    }
    if (lhs[0] == '-' && rhs[0] != '-'){
        lhs.erase(0,1);

        //std::stringstream strFirst(lhs);
        double dblFirst = 0;
        //strFirst >> intFirst;

        //std::stringstream strSecond(rhs);
        double dblSecond = 0;
        //strSecond >> intSecond;
        dblFirst = stod(lhs);
        dblSecond = stod(rhs);


        if(dblFirst < dblSecond)
            swap(lhs,rhs);

        int j = rhs.length() - 1;
        for(int i = lhs.length() - 1; i < lhs.length(); i--){
            sum = (lhs[i]-'0') + (rhs[j]-'0') + carry;
            if(carry == 1)
                carry--;
            if(sum > 9){
                carry++;
                sum -= 10;
            }
            helper = std::to_string(sum);
            result.insert(0,helper);
            if (i == 0 && j == 0 && carry == 1){
                result.insert(0,"1");
            }
            if (j == 0 && i != 0){
                i--;
                for(int k = i; i >= 0; k--){
                    sum = lhs[k] - '0' + carry;
                    if(sum > 9){
                        carry = 1;
                        sum -= 10;
                    } else {
                        carry = 0;   
                    }
                    helper = std::to_string(sum);
                    result.insert(0,helper);
                    i--;
                    if (k == 0 && carry == 1){
                        result.insert(0,"1");
                    }  
                } 
                break;
            }
            j--;
        }
        result.insert(0,"-");
    }
    if (lhs[0] != '-' && rhs[0] == '-'){

        rhs.erase(0,1);

        if(lhs.size() < rhs.size())
            swap(lhs,rhs);
        int j = rhs.length() - 1;
        for(int i = lhs.length() - 1; i < lhs.length(); i--){
            sum = (lhs[i]-'0') + (rhs[j]-'0') + carry;
            if(carry == 1)
                carry--;
            if(sum > 9){
                carry++;
                sum -= 10;
            }
            helper = std::to_string(sum);
            result.insert(0,helper);
            if (i == 0 && j == 0 && carry == 1){
                result.insert(0,"1");
            }
            if (j == 0 && i != 0){
                i--;
                for(int k = i; i >= 0; k--){
                    sum = lhs[k] - '0' + carry;
                    if(sum > 9){
                        carry = 1;
                        sum -= 10;
                    } else {
                        carry = 0;   
                    }
                    helper = std::to_string(sum);
                    result.insert(0,helper);
                    i--;
                    if (k == 0 && carry == 1){
                        result.insert(0,"1");
                    }  
                } 
                break;
            }
            j--;
        }
    }


    return result;

}

string multiply(string lhs, string rhs) {
    string middle = "";
    string helper;
    string zeros = "";
    string result = "";
    string addition = "";
    int sum;
    int product;
    int carry = 0;
    int addNegative = 1;
    int remainder = 0;

    if (lhs[0] == '-' && rhs[0] == '-'){
        lhs.erase(0,1);
        rhs.erase(0,1);
    } else if (lhs[0] == '-'){
        addNegative = 0;
        lhs.erase(0,1);
    } else if (rhs[0] == '-'){
        addNegative = 0;
        rhs.erase(0,1);
    }

    if(lhs.size() < rhs.size())
        swap(lhs,rhs);

    for(int k = rhs.length() - 1; k < rhs.length(); k--){            
        middle.insert(0,zeros);                     //zeros spaces
        
        for(int a = lhs.length() - 1; a < lhs.length(); a--){
            product = (lhs[a] - '0') * (rhs[k] - '0') + carry; //
            carry = 0;

            if (product > 9 && a != 0){        //
                carry = product / 10;
                product = product % 10;
            }
            helper = std::to_string(product);
            middle.insert(0,helper);
        }
        zeros.insert(0,"0");

        if(addition.size() < middle.size())
            swap(addition,middle);
        if(addition == "")
            swap(addition,middle);
 
        int j = middle.length() - 1;
        int i = addition.length() - 1;
        while(i >= 0){
            if (middle == ""){
                sum = (addition[i]-'0') + remainder;                
            }
            else
                sum = (addition[i]-'0') + (middle[j]-'0') + remainder;
            remainder = 0;
            if (sum > 9){
                sum = sum % 10;
                remainder = 1;
            }
            helper = std::to_string(sum);
            result.insert(0,helper);
            i--;
            j--;
            if(j < 0){
                while(i >= 0){
                    sum = addition[i]-'0' + remainder;
                    remainder = 0;
                    if (sum > 9){
                        sum = sum % 10;
                        remainder = 1;
                    }
                    helper = std::to_string(sum);
                    result.insert(0,helper);
                    i--;
                }                
            }
        
        }
        swap(addition,result);
        result = "";
        middle = "";

        if(remainder == 1){
            addition.insert(0,"1");
            remainder = 0;
        }
    }

    
    if(addNegative == 0){
        addition.insert(0,"-");
    }

    return addition;
}
