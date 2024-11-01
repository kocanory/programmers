int main(void) {
    int number;
    cin >> number;
    
    int answer = 0;
    
    for(;number > 0;){
        answer += number % 100;
        number /= 100;
    }
    cout << answer << endl;
    return 0;
}