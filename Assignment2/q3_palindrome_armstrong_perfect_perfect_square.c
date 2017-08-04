#include<stdio.h>
#include<math.h>

int main() {
    int n;

    printf("Enter a no : ");
    scanf("%d",&n);

    printf("\nThe number %d is :\n",n);

    isPalindrome(n)?printf("- Palindrome\n"):printf("- Not Palindrome\n");
    isArmstrong(n)?printf("- Armstrong\n"):printf("- Not Armstrong\n");
    isPerfect(n)?printf("- Perfect\n"):printf("- Not Perfect\n");
    isPerfectSquare(n)?printf("- Perfect Square\n"):printf("- Not Perfect Square\n");

    return 0;
}

int isPalindrome(int num) {
    int rev = 0,store = num;
    while(num) {
        rev *= 10;
        rev += num%10;
        num = num/10;
    }
    // return 1 if equal, else 0
    return (rev == store);
}

int isArmstrong(int num) {
    int digits=0,i,temp=num,sum=0,rem;
    //counting how many digits
    while(temp) {
        digits++;
        temp/=10;
    }
    temp=num;
    // sum of (i-th term ^ digits)
    while(temp) {
        rem=temp%10;
        sum+=intpow(rem,digits);
        temp/=10;
    }
    // return 1 if equal, else 0
    return (sum == num);
}

int isPerfect(int num) {
    int i,sum=0;
    // sum of (i-th term ^ digits)
    for(i=1;i<num;i++){
        if(num%i == 0){
            sum += i;
        }
    }
    // return 1 if equal, else 0
    return (sum == num);
}

int isPerfectSquare(int num) {
    // generating closest root, truncated to pure integer
    int closest_root = sqrt(num);
    // return 1 if equal, else 0
    return (num == (closest_root*closest_root));
}

int intpow(int num, int pow) {
    int res = 1;
    while(pow) {
        res *= num;
        pow--;
    }
    return res;
}
