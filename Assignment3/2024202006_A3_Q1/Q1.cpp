#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string removeLeadingZeros(string str) 
{
    int i = 0;
    while (i < str.length() - 1 && str[i] == '0') i++;
    return str.substr(i);
}

string add(string num1, string num2) {
    string result = "";
    int carry = 0;
    int n1 = num1.length(), n2 = num2.length();
    int i = n1 - 1, j = n2 - 1;
    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if(i >= 0) sum += num1[i--] - '0';
        if(j >= 0) sum += num2[j--] - '0';
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
    }
    return removeLeadingZeros(result);
}

string subtract(string num1, string num2) {
    string result = "";
    int borrow = 0;
    int n1 = num1.length(), n2 = num2.length();
    int i = n1 - 1, j = n2 - 1;
    while(i >= 0) {
        int diff = (num1[i] - '0') - borrow;
        if(j >= 0) diff -= (num2[j--] - '0');
        if(diff < 0) {
            diff += 10;
            borrow = 1;
        } else borrow = 0;
        result = char(diff + '0') + result;
        i--;
    }
    return removeLeadingZeros(result);
}

string multiply(string num1, string num2) {
    int n1 = num1.length(), n2 = num2.length();
    int resultLen = n1 + n2;
    int *result = new int[resultLen];
    memset(result, 0, resultLen * sizeof(int));
    
    for(int i = n1 - 1; i >= 0; i--) {
        for(int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i]-'0') * (num2[j]-'0');
            int sum = result[i+j+1] + mul;
            result[i+j+1] = sum % 10;
            result[i+j] += sum / 10;
        }
    }
    
    string s = "";
    for(int i = 0; i < resultLen; i++) {
        s += char(result[i] + '0');
    }
    delete[] result;
    return removeLeadingZeros(s);
}

string divide(string dividend, string divisor) {
    if(divisor == "0") return "Undefined";
    string result = "";
    string temp = "";
    int idx = 0;
    while(idx < dividend.length()) {
        temp += dividend[idx++];
        temp = removeLeadingZeros(temp);
        int count = 0;
        while(temp.length() > divisor.length() || (temp.length() == divisor.length() && temp >= divisor)) {
            temp = subtract(temp, divisor);
            count++;
            temp = removeLeadingZeros(temp);
        }
        result += char(count + '0');
    }
    return removeLeadingZeros(result);
}

string power(string base, long long exponent) {
    string result = "1";
    while(exponent > 0) {
        if(exponent % 2 == 1) result = multiply(result, base);
        base = multiply(base, base);
        exponent /= 2;
    }
    return removeLeadingZeros(result);
}

string gcd(string a, string b) {
    while(b != "0") {
        string temp = b;
        b = subtract(a, multiply(divide(a, b), b));
        a = temp;
    }
    return a;
}

string factorial(string n) {
    string result = "1";
    string one = "1";
    while(n != "0" && n != "1") {
        result = multiply(result, n);
        n = subtract(n, one);
    }
    return result;
}

bool isGreaterOrEqual(string num1, string num2) {
    num1 = removeLeadingZeros(num1);
    num2 = removeLeadingZeros(num2);
    if(num1.length() > num2.length()) return true;
    if(num1.length() < num2.length()) return false;
    return num1 >= num2;
}

int tokenize(string expr, string tokens[], int &count) {
    int n = expr.length();
    string num = "";
    count = 0;
    for(int i = 0; i < n; i++) {
        char ch = expr[i];
        if(ch >= '0' && ch <= '9') {
            num += ch;
        } else {
            if(num != "") {
                tokens[count++] = num;
                num = "";
            }
            tokens[count++] = string(1, ch);
        }
    }
    if(num != "") tokens[count++] = num;
    return count;
}

string evaluateExpression(string tokens[], int count) {
    for(int i = 0; i < count; i++) {
        if(tokens[i] == "x" || tokens[i] == "/") {
            string left = tokens[i - 1];
            string right = tokens[i + 1];
            string result;
            if(tokens[i] == "x") {
                result = multiply(left, right);
            } else {
                result = divide(left, right);
            }
            tokens[i - 1] = result;
            for(int j = i; j < count - 2; j++) {
                tokens[j] = tokens[j + 2];
            }
            count -= 2;
            i--;
        }
    }
    for(int i = 0; i < count; i++) {
        if(tokens[i] == "+" || tokens[i] == "-") {
            string left = tokens[i - 1];
            string right = tokens[i + 1];
            string result;
            if(tokens[i] == "+") {
                result = add(left, right);
            } else {
                if(isGreaterOrEqual(left, right)) {
                    result = subtract(left, right);
                } else {
                    result = "0"; 
                }
            }
            tokens[i - 1] = result;
            for(int j = i; j < count - 2; j++) {
                tokens[j] = tokens[j + 2];
            }
            count -= 2;
            i--;
        }
    }
    return tokens[0];
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while(T--) {
        int operationType;
        cin >> operationType;
        cin.ignore();

        if(operationType == 1 || operationType == 4) {
            string input;
            getline(cin, input);
            if(operationType == 1) {
                string tokens[1000];
                int count = 0;
                tokenize(input, tokens, count);
                string result = evaluateExpression(tokens, count);
                cout << result << endl;
            } else {
                string n = input;
                string result = factorial(n);
                cout << result << endl;
            }
        } else if(operationType == 2) {
            string base, exponentStr;
            cin >> base >> exponentStr;
            long long exponent = 0;
            for(char c : exponentStr) {
                exponent = exponent * 10 + (c - '0');
            }
            string result = power(base, exponent);
            cout << result << endl;
        } else if(operationType == 3) {
            string num1, num2;
            cin >> num1 >> num2;
            string result = gcd(num1, num2);
            cout << result << endl;
        }
    }
    return 0;
}
