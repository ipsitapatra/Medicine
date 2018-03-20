int s=23;
int m=12;
int h=14;
int day=1;
int i=0;

int buttonstatefever=0;
int buttonstatepet=0;

int hourarrlnch[7]={0,0,0,0,0,0,0};
int minutearrlnch[7]={0,0,0,0,0,0,0};
int houravglnch=0;
int minuteavglnch=0;

int hourarrdnr[7]={0,0,0,0,0,0,0};
int minutearrdnr[7]={0,0,0,0,0,0,0};
int houravgdnr=0;
int minuteavgdnr=0;

void setup()
{
  pinMode(3,INPUT);//lnchWalaSwitch
  pinMode(4,INPUT);//dnrWalaSwitch

  pinMode(5,INPUT);//feverWalaSwitch
  pinMode(6,INPUT);//petWalaSwitch
  
  pinMode(12,OUTPUT);//lnchSwitch k upar LED
  pinMode(11,OUTPUT);//dnrSwitch k upar LED

  pinMode(10,OUTPUT);//feverLED
  pinMode(9,OUTPUT);//petLED

  pinMode(7,OUTPUT);//buzzer

  pinMode(1,OUTPUT);//after lunch
  pinMode(2,OUTPUT);//after dnr
  
  Serial.begin(9600);
}

void loop()
{
      if(h==houravglnch && m=minuteavglnch)
      {
          buzzer();
          digitalWrite(1,HIGH);
          delay(10);
          digitalWrite(1,LOW);
          delay(10);
      }

      if(h==houravgdnr && m=minuteavgdnr)
      {
          buzzer();
          digitalWrite(2,HIGH);
          delay(10);
          digitalWrite(2,LOW);
          delay(10);
      }
      
      int buttonStatelnch=digitalRead(3);
      int buttonStatednr=digitalRead(4);

      buttonstatefever=digitalRead(5);
      if(buttonstatefever==1)
      {
          digitalWrite(10,HIGH);
          buzzer();
      }
      else
      {
        digitalWrite(10,LOW);
      }
      
      buttonstatepet=digitalRead(6);
       if(buttonstatepet==1)
      {
          digitalWrite(9,HIGH);
          buzzer();
      }
      else
      {
        digitalWrite(9,LOW);
      }
      
      if(s>59) {m=m+1; s=0; } 
      if(m>59) { h=h+1; m=0; } 
      if(h>24) { h=0; m=0; s=0; day=day+1; } 
      delay(1000); 
      s=s+1; 
    //  Serial.print(h);Serial.print(":");Serial.print(m);Serial.print(":");Serial.print(s);
      Serial.print("\n"); 

      if(buttonStatelnch==1)
      {
        Serial.print("Hour : ");
        Serial.println(h);
        Serial.print("Minute : ");
        Serial.println(m);
          pass(hourarrlnch);
          pass(minutearrlnch);
          enterData(hourarrlnch,h);
          enterData(minutearrlnch,m);
          displayTime(hourarrlnch,minutearrlnch); 
          houravglnch = avg(hourarrlnch);
          minuteavglnch = avg(minutearrlnch);
        digitalWrite(12,HIGH);
      }
      else
      {
          digitalWrite(12,LOW);
      }

      if(buttonStatednr==1)
      {
        Serial.print("Hour : ");
        Serial.println(h);
        Serial.print("Minute : ");
        Serial.println(m);
          pass(hourarrdnr);
          pass(minutearrdnr);
          enterData(hourarrdnr,h);
          enterData(minutearrdnr,m);
          displayTime(hourarrdnr,minutednr); 
          houravgdnr = avg(hourarrdnr);
          minuteavgdnr = avg(minutearrdnr);
        digitalWrite(11,HIGH);
      }
      else
      {
          digitalWrite(12,LOW);
          digitalWrite(11,LOW);
      }
}

void displayTime(int hourarr[],int minutearr[])
{
  for(i=0;i<7;i++)
  {
      Serial.print(hourarr[i]);
  }
  Serial.println("\n");
  for(i=0;i<7;i++)
  {
      Serial.print(minutearr[i]);
  }
  Serial.println("\n");
}

void pass(int arr[])
{
      arr[6]=arr[5];
      arr[5]=arr[4];
      arr[4]=arr[3];
      arr[3]=arr[2];
      arr[2]=arr[1];
      arr[1]=arr[0];
}

void enterData(int a[],int data)
{
      a[0]= data;
}
int avg(int a[])
{
  int sum=0;
    for(i=0;i<7;i++)
    {
      sum=sum+a[i];
    }
    Serial.print("Avg : ");
    Serial.println(sum/7.0);
    return (sum/7.0);
}

void buzzer()
{
    for(i=0;i<10;i++)
    {
      digitalWrite(7,HIGH);
      delay(200);
      digitalWrite(7,LOW);
      delay(200);
    }
    
}
