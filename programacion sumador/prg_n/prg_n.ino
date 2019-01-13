  int a = 2;
  int b = 3;
  int c = 4;
  int d = 5;
  int e = 6;
  int f = 7;
  int g = 8;
  int da = 9;
  int db = 10;
  int dc = 11;
  int dd = 12;
  int de = 13;
  int df = 14;
  int dg = 15;
 
  int x = 0;
  int y=0;

void setup() {
  // put your setup code here, to run once:
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
Serial.begin(9600);
  
}




void loop() {
  // put your main code here, to run repeatedly:
  x=0;
while (x<10)

if (y==0) {
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);

}

// aqui se analizan las decenas
if (y==1) {
digitalWrite(da,LOW);
digitalWrite(db,HIGH);
digitalWrite(dc,HIGH);
digitalWrite(dd,LOW);
digitalWrite(de,LOW);
digitalWrite(df,LOW);
digitalWrite(dg,LOW);

}
if (y==2) {
digitalWrite(da,HIGH);
digitalWrite(db,HIGH);
digitalWrite(dc,LOW);
digitalWrite(dd,HIGH);
digitalWrite(de,HIGH);
digitalWrite(df,LOW);
digitalWrite(dg,HIGH);

}
if (y==3 ) {
digitalWrite(da,HIGH);
digitalWrite(db,HIGH);
digitalWrite(dc,HIGH);
digitalWrite(dd,HIGH);
digitalWrite(de,LOW);
digitalWrite(df,LOW);
digitalWrite(dg,HIGH);

}
if (y==4 ) {
digitalWrite(da,LOW);
digitalWrite(db,HIGH);
digitalWrite(dc,HIGH);
digitalWrite(dd,LOW);
digitalWrite(de,LOW);
digitalWrite(df,HIGH);
digitalWrite(dg,HIGH);

}
if (y==5 ) {
digitalWrite(da,HIGH);
digitalWrite(db,LOW);
digitalWrite(dc,HIGH);
digitalWrite(dd,HIGH);
digitalWrite(de,LOW);
digitalWrite(df,HIGH);
digitalWrite(dg,HIGH);

}
if (y==6 ){
digitalWrite(da,HIGH);
digitalWrite(db,LOW);
digitalWrite(dc,HIGH);
digitalWrite(dd,HIGH);
digitalWrite(de,HIGH);
digitalWrite(df,HIGH);
digitalWrite(dg,HIGH);

}
if (y==7) {
digitalWrite(da,HIGH);
digitalWrite(db,HIGH);
digitalWrite(dc,HIGH);
digitalWrite(dd,LOW);
digitalWrite(de,LOW);
digitalWrite(df,LOW);
digitalWrite(dg,LOW);

}
if (y==8 ) {
digitalWrite(da,HIGH);
digitalWrite(db,HIGH);
digitalWrite(dc,HIGH);
digitalWrite(dd,HIGH);
digitalWrite(de,HIGH);
digitalWrite(df,HIGH);
digitalWrite(dg,HIGH);

}
if (y==9 )
{
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);

}
// aqui se analizan las unidades
{
Serial.println(x);
if (x==0) {
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);

}
if (x==1) {
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);

}
if (x==2) {
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);

}
if (x==3) {
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);

}
if (x==4) {
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);

}
if (x==5) {
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);

}
if (x==6){
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);

}
if (x==7) {
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);

}
if (x==8) {
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);

}
if (x==9)
{
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);


}
Serial.print(y);
Serial.print(x);
Serial.println(" ");



x=x+1;

delay(100);
}
 y=y+1;
}
