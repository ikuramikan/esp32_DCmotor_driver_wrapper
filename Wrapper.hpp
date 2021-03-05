#ifndef Wrapper.hpp
#define Wrapper.hpp

class Wrapper
{
private:
    // pinの番号
    const int r1_pin, r2_pin, l1_pin, l2_pin, r_ledc_pin, l_ledc_pin;

    // pwmのチャンネル
    int r_ledc_channel, l_ledc_channel;

    // HIGHかLOWの状態
    int r1_state, r2_state, l1_state, l2_state;

    // pwmのduty比
    int r_duty, l_duty;

    const int f;
    const int bits;
    bool flag;

    // helper
    void set_state(int new_r1_state, int new_r2_state, int new_l1_state, int new_l2_state);
    void set_duty(int new_r_ledc_duty, int new_l_ledc_duty);

    void set_rl_state(int state1, int state2);
    void set_rl_duty(int duty);

public:
    Wrapper(int r1_pin, int r2_pin, int l1_pin, int l2_pin, int r_ledc_pin, int l_ledc_pin, int f, int bits);
    void set_motion(int input);
};
#endif
