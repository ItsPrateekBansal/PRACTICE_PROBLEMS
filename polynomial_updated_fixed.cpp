class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    Polynomial()                                   //CONSTRUCTOR
    {
        degCoeff=new int[10];
        capacity=10;
        for(int i=0;i<capacity;i++)
            degCoeff[i]=0;
    }
    
   Polynomial(const Polynomial& p2)                //COPY CONSTRUCTOR
    {
        degCoeff = new int[p2.capacity];
        capacity = p2.capacity;
        
        for(int i =0;i<p2.capacity;i++)
        {
            degCoeff[i] = p2.degCoeff[i];
        }
    }
     void setCoefficient(int index,int coeff)
    {
        if(index<capacity)
        {
            degCoeff[index] = coeff;
        }
        else
        {
            int size = 2*capacity;
            while(size<=index)
                size=size*2;
            int * newData = new int[size];
            for(int i =0;i<capacity;i++)
            {
                newData[i] = degCoeff[i];
            }
            for(int i =capacity;i<size;i++)
                newData[i]=0;
            delete [] degCoeff;
            degCoeff = newData;
            capacity=size;
            degCoeff[index] = coeff;
        }
    
    }
      void print()                                           //print function
    {
        for(int i=0;i<capacity;i++)
        {
            if(degCoeff[i]!=0)
            {
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
    Polynomial operator+ (Polynomial const &P)              //addition operator overloading
    {
      Polynomial p;
      int x=min(this->capacity,P.capacity);
      int y=max(this->capacity,P.capacity);
      for(int i=0;i<x;i++)
      {
          p.setCoefficient(i,this->degCoeff[i]+P.degCoeff[i]);
      }
      if(y==this->capacity)
      for(int i=x;i<y;i++)
      {
          p.setCoefficient(i,degCoeff[i]);
      }
       if(y==P.capacity)
      for(int i=x;i<y;i++)
      {
          p.setCoefficient(i,P.degCoeff[i]);
      }
      return p;
    }
     Polynomial operator-(const Polynomial& p2)
    {
        Polynomial *p3 = new Polynomial();
        int *newdata = new int[capacity + p2.capacity];
        for(int i =0;i<capacity + p2.capacity;i++)
            newdata[i] = 0;
        delete [] p3->degCoeff;
        p3->degCoeff = newdata;
        p3->capacity = capacity + p2.capacity;
        int i = 0,j=0,k=0;
       while(i<capacity&& j<p2.capacity)
        {
            p3->degCoeff[k] = this->degCoeff[i] - p2.degCoeff[j];
           i++;
           j++;
           k++;
        }
        while(i<capacity && k<p3->capacity)
        {
            p3->degCoeff[k] = this->degCoeff[i];
            i++;
            k++;
        } 
        while(j<p2.capacity && k<p3->capacity)
        {
            p3->degCoeff[k] = -p2.degCoeff[j];
            j++;
            k++;
        }       
        return *p3;
    }
      Polynomial operator*(const Polynomial& p2)
    {
        Polynomial *p3 = new Polynomial();
        
        int *newdata = new int[capacity*p2.capacity];
        for(int i =0;i<capacity*p2.capacity;i++)
            newdata[i] = 0;
        
        delete [] p3->degCoeff;
        
        p3->degCoeff = newdata;
        
        p3->capacity = (capacity * p2.capacity);
        
        for(int i = 0;i<this->capacity;i++ )
        {
            for(int j =0;j<p2.capacity;j++)
            {
                p3->degCoeff[i+j] += this->degCoeff[i]*(p2.degCoeff[j]);
            }
            
        }
        
        return *p3;
    }
   void operator=(const Polynomial& p2)
    {
        this->capacity = p2.capacity;
        for(int i =0;i<capacity;i++)
        {
            this ->degCoeff[i] = p2.degCoeff[i];
        }
    }
    int getCoefficient(int degree){
        if(degree>=capacity){
            return 0;
        }
        return degCoeff[degree];
    }
    
};