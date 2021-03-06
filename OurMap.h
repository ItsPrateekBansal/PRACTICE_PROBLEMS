#include<string>
using namespace std;

template <typename V>
class mapnode{                                 //FOR SEPERATE CHAINING 
public:
	string key;
	V value;
	mapnode *next;
	mapnode(string key,V value)
	{
		this->key = key;
		this->value = value;
	}
	~mapnode()
	{
		delete next;
	}
};

template <typename V>                            
class ourmap{                                   //CREATING OUR OWN MAP
mapnode<V> **buckets;                           //THE ARRAY OF CHAINS......BUCKET ARRAY
int count;                                      //FOR MAINTAINING THE NUMBER OF KEYS  
int numBuckets;

ourmap()
{
	count=0;
	numBuckets=5;
	buckets = new Mapnode<V>*[numBuckets];
	for(int i=0;i<numBuckets;i++)
		buckets[i] = NULL;
}
~ourmap()
{
	for(int i=0;i<numBuckets;i++)
		delete buckets[i];
	delete [] buckets;
}

int size()
{
	retrurn count;
}
private:
int getBucketIndex(string key)                      //HERE WE CREATE OUR OWN HASHFUNCTION CONATINING TWO PARTS HASHCODE AND THE COMPRESSION FUNCTION
{
	int hashCode=0;
	int currentCoefficent = 1;
	for(int i=key.length()-1;i>=0;i--)                  //hashcode
	{
		hashCode+=key[i] * currentCoefficient;
		hashCode=hashCode % numBuckets;
		currentCoefficient*=37;
		currentCoefficient%numBuckets;
	}

	return hashCode % numBuckets;     //compression function
}
void rehash()                        //private function for rehashing 
{
    mapnode<V>** temp = buckets;
    buckets = new mapnode<V>*[2*numBuckets];
    for(int i=0;i<2*numBuckets;i++)
    {
        buckets[i]=NULL;
    }
    int oldBucketCount = numBuckets;
    numBuckets*=2;
    count =0;
    for(int i=0;i<oldBucketCount;i++)
    {
        mapnode<V>* head = temp[i];
        while(head!=NULL)
        {
            insert(head->key,head->value);
            head=head->next;
        }
    }
    for(int i=0i<oldBucketCount;i++)
    {
        mapnode<V>* head = temp[i];
        delete head;
    }
    delete [] temp;
}
public:
void insert(string key, V value)
{
	int bucketIndex = getBucketIndex(key);  //WHERE DO WE INSERT THE DESIRED VALUE WRT KEY
	mapnode<V>* head = buckets[bucketIndex];
	while(head!=NULL)
	{
		if(head->key == key){
			head->value=value;
	                return;
		}
		head=head->next;
	} 
	// IF THE KEY DOESN'T ALREADY EXIST, WE CREATE THE A NEW NODE INTO THE DESIRED CHAIN AT THE INDEX WRT TO THE KEY CALCULATED BY THE HASHFUNCTION
	head = buckets[bucketIndex];
	mapnode<V> node = new mapnode<V>(key,value);
	node->next = head;
	buckets[bucketIndex] = node;
	count++;     //SINCE NEW NODE IS CREATED WE NEED TO UPDATE THE COUNT
    double loadFactor = (1.0*count)/numBuckets;
    if(loadFactor>0.7)
    rehash();
}

V getvalue(string key)
{
int bucketIndex = getBucketIndex(key);
mapnode<V> *head = buckets[bucketIndex];
while(head!=NULL)
{
    if(head->key == key)
    return head->value;
    head=head->next;
}
return 0;
}


V remove(string key)
{
int bucketIndex = getBucketIndex(key);
mapnode<V> *head = buckets[bucketIndex];
mapnode<V> *prev = NULL;
while(head!=NULL)
{
	if(head->key==key){
		if(prev==NULL)
		{
        buckets[bucketsIndex] = head->next;
		
		}
		else{
		prev->next = head->next;
		}
        V x = head->value;
		head->next = NULL;
		delete head;
		count--;
		return x;
	}
	prev = head;
	head=head->next;
}
return 0;
}



}

