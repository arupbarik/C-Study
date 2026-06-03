#include <stdio.h>
#include <math.h>
int main(){
    printf("lets start\n");
    int x;
    scanf("\n%d", &x);
    switch(x){
        case 23:
        printf("the value is 23");
        break;
        case 45:
        printf("the value is 45");          
        break;
        default:
        printf("the value is neither 23 nor 45");
    }

    // smart traffic signal
     int n, s, e, w;
     printf("Enter vehicles on N S E W: ");
     scanf("%d %d %d %d", &n, &s, &e, &w);

        // N checked first = highest priority on tie
     if (n >= s && n >= e && n >= w)
          printf("You can go North!\n");
     else if (e >= s && e >= w)       // N already lost, so E is next priority
          printf("You can go East!\n");
     else if (s >= w)                 // N and E lost, S vs W
          printf("You can go South!\n");
     else
          printf("You can go West!\n");

    //Password Strength Checker
    int pwd;
    printf("enter your password:");
    scanf("%d",&pwd);
    if (pwd%7==0)
    {
      printf("Your password is Weak!!");
    }
    else if (pwd%5==0 && pwd%3==0)
    {
      printf("Your password is Moderate!!");
    }
    else if (pwd%11==0 && pwd%2!=0)
    {
      printf("Your password is Strong!!");
    }
    else{
      printf("Your password is Invalid!!");
    }

    //Triangle Intelligence System
    int a,b,c;
    printf("Enter your angles here:\n");
    scanf("%d %d %d",&a,&b,&c);
    int sum=a+b+c;
    if (sum==180 && a > 0 && b > 0 && c > 0 )
    {
      if (a==90 || b==90 || c==90)
      {
         printf("it is a right angle triangle");
      }
      else if (a<90 && b<90 && c<90)
      {
         printf("it is an acute angle triangle");
      }
      else
      {
         printf("it is an obtuse angle triangle");
      } 
    }
    else
    {
      if (a <= 0 || b <= 0 || c <= 0)
      {
         printf("Invalid: angles must be positive\n");
      }
      else
      {
         printf("Invalid: sum is not 180\n");
      }
    }
    
    //Electricity Billing with Slab Twist
    int units;
    float bill;
    printf("enter your units consumed:\n");
    scanf("%d",&units);
    if (units<=100)
    {
      bill= units*1;
    }
    else if (units<=200)
    {
      bill= (100*1)+(units-100)*2;
    }
    else if (units<=300)
    {
      bill= (100*1)+(100*2)+(units-200)*3;
    }
    else if (units>300)
    {
      bill= (100*1)+(100*2)+(100*3)+(units-300)*5;
    }
    
    if (units<=50 && units>0)
    {
      bill=100;
    }
    if (bill>500)
    {
      bill= bill*0.9;
    }
    printf("so your total bill is %.2f", bill);

    //Game Score Analyzer
    int p,o,diff;
    printf("enter your player score\n");
    scanf("%d", &p);
    printf("enter your opponent score\n");
    scanf("%d", &o);
    diff= p-o;
    if (diff>50)
    {
      printf("Win by domination");
    }
    else if (diff>0 && diff<=10)
    {
      printf("close win");
    }
    else if (diff>=-10 && diff<0)
    {
      printf("Loss but good fight");
    }
    else if (diff<-50)
    {
      printf("crushed");
    }
    else if (diff==0)
    {
      printf("Draw");
    }
    else
    {
      printf("Win but good fight");
    }

    // ATM Withdrawal Logic
    int bal,wa;
    printf("please enter your balance and witdrawl amount:\n");
    scanf("%d %d",&bal,&wa);

    if (wa%100!=0)
    {
      printf("PLease enter amount in multiple of 100");
    }
    else if (wa>bal)
    {
      printf("insufficient balance");
    }
    
    else if ((bal-wa)<500)
    {
      printf("please maintain min. balance of 50 0");
    }
    else if (wa>10000)
    {
      printf("please providee extra validation");
    }
    else
    {
      printf("successful transaction. remaining balace is Rs. %d",bal-wa);
    }

    //Character Mystery Solver
    char ch;
    printf("please enter\n");
    scanf("%c",&ch);
    if (ch>='A' && ch<='Z')
    {
      printf("UPPERCASE");
    }
    else if (ch>='a' && ch<='z')
    {
      printf("lowercase");
    }
    else if (ch>='0'&& ch<='9')
    {
      if (ch%2==0)
      {
         printf("even digit");
      }
      else
      {
         printf("odd digit");
      }
    }
    else
    {
      printf("special character");
    }

    //Switch-Based Mini Calculator
    int y,z;
    char op;
    printf("please enter two numbers:\n");
    scanf("%d %c %d", &y, &op,&z);
    switch (op)
    {
    case '+':
      printf("sum is %d", y+z);
      break;
    case '-':
      printf("substration is %d", y-z);
      break;
    case '*':
      printf("multiplication is %d", y*z);
      break;
    case '/':
      if (z==0)
      {
         printf("It cant be executed");
      }
      else
      {
         printf("divition is %d", y/z);
      }
      break;
    default:
    printf("unknown operation");
      break;
    }

    //Temperature Advisory System
   int temp;
   printf("please enter temperatue\n");
   scanf("%d",&temp);
   if (temp<0)
   {
      printf("dead frezzing!!");
   }
   else if (temp>=0 && temp<=15)
   {
      printf("Cold!!");
   }
   else if (temp>=16 && temp<=30)
   {
      printf("comfortable!!");
   }
   else if (temp>=31 && temp<=45)
   {
      if (temp>40)
      {
         printf("It's Hot but stay hydrated!!");
      }
      else
      {
         printf("Hot!!");
      }
   }
   else
   {
      printf("Extreme Danger");
   }

    // Voting Eligibility System
    int age, citizen;
    printf("enter your age and citizenship\n");
    scanf("%d %d",&age,&citizen);
    if (age<18 && citizen==0)
    {
      printf("Not eligible due to both");
    }
    else if (age>=18 && citizen==0)
    {
      printf("Not eligible due to citizenship");
    }
    else if (age<18 && citizen==1)
    {
      printf("Not eligible due to age");
    }
    else
    {
      printf("Eligible");
    }
    
    //Number Pattern Decision Maker
    int num;
    printf("enter your number\n");
    scanf("%d",&num);
    if (num%2==0 && num%3==0)
    {
        printf("FizzBuzz\n");
    }
    else if (num%2==0)
    {
        printf("Fizz\n");
    }
    else if (num%3==0)
    {
        printf("Buzz\n");
    }
    else
    {
        printf("the number is %d\n", num);
    }
    
    //Scholarship Eligibility
    int marks;
    float income;
    printf("enter your marks(0-100) and family income\n");
    scanf("%d %f", &marks,&income);
    if (marks>100)
    {
        printf("please enter valid input in marks");
    }
    else if (marks>=90 && income<200000)
    {
        printf("Full scholarship");
    }
    else if (marks>=75 && income<500000)
    {
        printf("Partial scholarship");
    }
    else
    {
        printf("No scholarship");
    }

    //Day Type Detector
    int day;
    printf("enter your number\n");
    scanf("%d",&day);
    switch (day)
    {
    case 1:
        printf("Monday- Weekday");
        break;
    case 2:
        printf("Tuesday- Weekday");
        break;
    case 3:
        printf("Wednsday- Weekday");
        break;
    case 4:
        printf("Thrusday- Weekday");
        break;
    case 5:
        printf("Friday- Weekday");
        break;
    case 6:
        printf("Saturday- Weekend");
        break;
    case 7:
        printf("Sunday- Weekend");
        break;
    default:
        printf("Invalid input");
        break;
    }

    //Magic Number Classification
    int mn, original, rev = 0, temps, digitSum = 0;
    int isPalin, isEvenSum;

    printf("Enter a number: ");
    scanf("%d", &mn);

    original = mn;
    temps = (mn < 0) ? -mn : mn;  // handle negatives

    // Calculate reverse and digit sum together
    while (temps > 0) {
        int digit = temps % 10;
        rev = rev * 10 + digit;
        digitSum += digit;
        temps /= 10;
    }

    isPalin   = (original == rev);
    isEvenSum = (digitSum % 2 == 0);

    if (isPalin && isEvenSum)
        printf("Special Magic Number\n");
    else if (isPalin)
        printf("Mirror Number\n");
    else if (isEvenSum)
        printf("Balanced\n");
    else
        printf("Normal\n");
    return 0; 
}
