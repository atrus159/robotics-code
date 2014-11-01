#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     liftOne,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     liftTwo,       tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     liftThree,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void extend(int toExtend);
void retract(int toRetract);
void act(int action, int toAct);
void goTo(int toGo);

int position;

int procedures[4][4]= 
{{111,112,122,222},
{110,111,121,221},
{100,101,111,211},
{000,001,011,111}};

task main()
{
nMotorEncoder[liftOne]=0;
nMotorEncoder[liftTwo]=0;
nMotorEncoder[liftThree]=0;
position=0;

goTo(3);

wait1msec(2000);

goTo(1);

wait1msec(2000);

goTo(2);

wait1msec(2000);

goTo(0);

}

void extend(int toExtend){
	//replace 1 with 5 in final version
while(nMotorEncoder[toExtend]<1*1120){
motor[toExtend]=50;
}
motor[toExtend]=0;

}

void retract(int toRetract){

while(nMotorEncoder[toRetract]>0){
motor[toRetract]=-50;
}
motor[toRetract]=0;

}

void goTo(int toGo){
 int procedure = procedures[position][toGo];
 int action1 = procedure%10;
 int action2 = floor(procedure/10)%10;
 int action3 = floor(procedure/100)%10;
 act(action1,liftOne);
 act(action2,liftTwo);
 act(action3,liftThree);
 position=toGo;
}

void act(int action, int toAct){
	if(action==0){
	retract(toAct);	
 }
 else if(action==2){
  extend(toAct); 
 }
}
