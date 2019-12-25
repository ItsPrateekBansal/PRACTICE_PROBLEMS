int pow(int m)
{
    if(m==0)
        return 1;
    else 
        return 10*pow(m-1);
}

int help(char input[],int size)
{
if(input[0]=='\0')
    return 0;
else 
    return ( pow(size-1)*(input[0]-48) + help(input+1,size-1) );
}




int stringToNumber(char input[]) {
    // Write your code here
 
   int i=0;
    while(input[i]!=0)
        i++;
   int ans = help(input,i);  
    return ans;
}
