###################### servo code without servo drivers ######################
#include <Servo.h>
Servo base_r;  //1
Servo base_l;  //2
Servo elbow;   //3
Servo claw;    //4

int mv = 20;  // each time moves 10 degree
char cmd = 'g';  // Nutral value
//int elbow_up = 0;
//int elbow_down = 0;
//gripper is not necessary  :3


///////////////////////////////////
int base_default = 180;     // base will decrease
int elbow_default = 0;      // elbow will increase
int claw_default = 180;    // grip open ....    /// 180 degree
//////////////////////////////////

void setup() {
  base_r.attach(9);
  base_l.attach(10);
  elbow.attach(11);
  claw.attach(12);
    base_r.write(base_default);
  base_l.write(180 - base_default);
  elbow.write(elbow_default);
  claw.write(claw_default);
  Serial.begin(9600);

}

void loop() {

  if (Serial.available() > 0) {
    cmd = Serial.read();
  }
  if (cmd == 'b') { // base moves up
    base_default = base_default - mv;
    base_r.write(base_default);
    base_l.write(180 - base_default);
    delay(500);
    Serial.write(cmd);
    cmd = 'g';
  }
  if (cmd == 'v') {  // base moves down
    base_default = base_default + mv;
    base_r.write(base_default);
    base_l.write(180 - base_default);
    delay(500);
    Serial.write(cmd);
    cmd = 'g';
  }
  if (cmd == 'e') { //elbow moves up
    elbow_default = elbow_default + mv;
    elbow.write(elbow_default);
    Serial.write(cmd);
    cmd = 'g';
  }
  if (cmd == 'w') { //elbow moves down
    elbow_default = elbow_default - mv;
    elbow.write(elbow_default);
    Serial.write(cmd);
    cmd = 'g';
  }
  if (cmd == 'c') { //claw opens up
    claw.write(180);
    Serial.write(cmd);
    cmd = 'g';
  }
  if (cmd == 'x') { //claw closes
    claw.write(0);
    Serial.write(cmd);
    cmd = 'g';
  }
}
