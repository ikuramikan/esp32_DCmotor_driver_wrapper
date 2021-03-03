#include "Wrapper.hpp"
#include "Arduino.h"

Wrapper::Wrapper(int r1_pin, int r2_pin, int l1_pin, int l2_pin, int r_ledc_pin, int l_ledc_pin, int f = 3000, int bits=8)
    :r1_pin(r1_pin), r2_pin(r2_pin), l1_pin(l1_pin), l2_pin(l2_pin), r_ledc_pin(r_ledc_pin), l_ledc_pin(l_ledc_pin), f(f), bits(bits)
{
    r_ledc_channel = 0;
    l_ledc_channel = 1;

    ledcSetup(r_ledc_channel, f, bits);
    ledcSetup(l_ledc_channel, f, bits);

    ledcAttachPin(r_ledc_channel, r_ledc_pin);
    ledcAttachPin(l_ledc_channel, l_ledc_pin);

    pinMode(r1_pin, OUTPUT);
    pinMode(r2_pin, OUTPUT);
    pinMode(l1_pin, OUTPUT);
    pinMode(l2_pin, OUTPUT);

    r_ledc_duty = 0;
    l_ledc_duty = 0;

    r1_state = LOW;
    r2_state = LOW;
    l1_state = LOW;
    l2_state = LOW;

    digitalWrite(r1_pin, r1_state);
    digitalWrite(r2_pin, r2_state);
    digitalWrite(l1_pin, l1_state);
    digitalWrite(l2_pin, l2_state);

    ledcWrite(r_ledc_channel, r_ledc_duty);
    ledcWrite(l_ledc_channel, l_ledc_duty);
}

void Wrapper::set_state(int new_r1_state, int new_r2_state, int new_l1_state, int new_l2_state)
{
    r1_state = new_r1_state;
    r2_state = new_r2_state;
    l1_state = new_l1_state;
    l2_state = new_l2_state;
}

void Wrapper::set_duty(int new_r_ledc_duty, int new_l_ledc_duty)
{
    r_ledc_duty = new_r_ledc_duty;
    l_ledc_duty = new_l_ledc_duty;
}

void set_rl_state(int state1, int state2)
{
    set_state(state1, state2, state1, state2);
}

void set_rl_duty(int duty)
{
    set_duty(duty, duty);
}

void set_motion(int input)
{
    if(input < 0)
    {
        input *= -1;
        set_rl_state(LOW, HIGH);
    }
    else
    {
        set_rl_state(HIGH, LOW);
    }
    set_rl_duty(input);
}