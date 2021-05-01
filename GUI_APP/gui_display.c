#include "gui_display.h"
#include "main.h"

LV_FONT_DECLARE(date_font_24);
LV_FONT_DECLARE(time_font_80);
LV_FONT_DECLARE(S_click_font);
LV_FONT_DECLARE(S_display_font);
LV_FONT_DECLARE(S_btn_font);
LV_FONT_DECLARE(S_dialog_text_font1);
LV_FONT_DECLARE(S_text_font);

ui_typdef_t smart_farm;
//gizwitsProtocol_t gizwits;
extern uint16_t time[5];
extern DHT11_Data_TypeDef dht11_data;



void smart_farm_display(void)
{
    /*设置背景色*/
    lv_obj_t* scr = lv_scr_act();
    lv_obj_t* bg_layer = lv_obj_create(scr, NULL);
    lv_obj_set_pos(bg_layer, 0, 0);
    lv_obj_set_size(bg_layer, 800, 480);
    static lv_style_t bg_layer_style;
    lv_style_copy(&bg_layer_style, &lv_style_plain_color);
    bg_layer_style.body.main_color = LV_COLOR_BLACK;
    bg_layer_style.body.grad_color = LV_COLOR_BLACK;
    lv_obj_set_style(bg_layer, &bg_layer_style);

    /*显示时间背景框*/
    lv_obj_t* time_bg = lv_obj_create(scr, NULL);
    lv_obj_set_size(time_bg, 200, 180);
    lv_obj_set_pos(time_bg, 25, 20);

    static lv_style_t time_gb_style;
    lv_style_copy(&time_gb_style, &lv_style_plain_color);
    time_gb_style.body.main_color = LV_COLOR_MAKE(0x87, 0xce, 0xfa);
    time_gb_style.body.grad_color = LV_COLOR_MAKE(0x80, 0x80, 0x80);
    time_gb_style.body.radius = 10;
    lv_obj_set_style(time_bg, &time_gb_style);

    /*设置日期*/
    smart_farm.time.date_text = lv_label_create(time_bg, NULL);
    static lv_style_t date_text_style;
    lv_style_copy(&date_text_style, &lv_style_plain_color);//样式拷贝
    date_text_style.text.font = &lv_font_roboto_22;//在样式中使用字体
    date_text_style.body.main_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    date_text_style.body.grad_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    date_text_style.text.color = LV_COLOR_BLACK;
    lv_label_set_style(smart_farm.time.date_text, LV_LABEL_STYLE_MAIN, &date_text_style);//设置样式
    lv_label_set_text(smart_farm.time.date_text, "2021-05-10");
    lv_obj_align(smart_farm.time.date_text, time_bg, LV_ALIGN_IN_TOP_MID, 0, 0);
    lv_task_create(update_date_cb, 100, LV_TASK_PRIO_MID, NULL);

    /*设置时间*/
    smart_farm.time.time_text = lv_label_create(time_bg, NULL);
    static lv_style_t time_text_style;
    lv_style_copy(&time_text_style, &lv_style_plain_color);//样式拷贝
    time_text_style.text.font = &time_font_80;//在样式中使用字体
    time_text_style.body.main_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    time_text_style.body.grad_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    time_text_style.text.color = LV_COLOR_BLACK;
    lv_label_set_style(smart_farm.time.time_text, LV_LABEL_STYLE_MAIN, &time_text_style);
    lv_label_set_text(smart_farm.time.time_text, "12:00");
    lv_obj_align(smart_farm.time.time_text, time_bg, LV_ALIGN_CENTER, 0, 0);
    lv_task_create(update_time_cb, 100, LV_TASK_PRIO_MID, NULL);

    /*控制台*/
    /*设置控制设备的图标样式*/
    static lv_style_t icon_style;
    lv_style_copy(&icon_style, &lv_style_plain);
    icon_style.text.font = &S_click_font;//在样式中使用这个字体
    icon_style.text.color = LV_COLOR_MAKE(0x87, 0xce, 0xfa);
    icon_style.body.main_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    icon_style.body.grad_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    /*控制台背景*/
    lv_obj_t* control_bg = lv_obj_create(scr, NULL);
    lv_obj_set_size(control_bg, 200, 230);
    lv_obj_set_pos(control_bg, 25, 225);

    static lv_style_t control_gb_style;
    lv_style_copy(&control_gb_style, &lv_style_plain_color);
    control_gb_style.body.main_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    control_gb_style.body.grad_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    control_gb_style.body.radius = 10;
    lv_obj_set_style(control_bg, &control_gb_style);

    /*显示控制台字样*/
    lv_obj_t* control_text = lv_label_create(control_bg, NULL);
    static lv_style_t control_text_style;
    lv_style_copy(&control_text_style, &lv_style_plain_color);//样式拷贝
    control_text_style.text.font = &lv_font_roboto_28;//在样式中使用字体
    control_text_style.body.main_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    control_text_style.body.grad_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    control_text_style.text.color = LV_COLOR_BLACK;
    lv_label_set_style(control_text, LV_LABEL_STYLE_MAIN, &control_text_style);//设置样式
    lv_label_set_text(control_text, "Control panel");
    lv_obj_align(control_text, control_bg, LV_ALIGN_IN_TOP_MID, 0, 0);

   /*显示风扇图标*/
    smart_farm.control_obj.fan = lv_label_create(control_bg, NULL);
    smart_farm.dialog_obj.fan_dialog = NULL;
    lv_obj_set_pos(smart_farm.control_obj.fan, 25, 150);
    lv_label_set_style(smart_farm.control_obj.fan, LV_LABEL_STYLE_MAIN, &icon_style);
    lv_label_set_text(smart_farm.control_obj.fan, FAN);//设置文本
    lv_obj_set_click(smart_farm.control_obj.fan, true);
    lv_obj_set_event_cb(smart_farm.control_obj.fan, control_event_handler);//注册事件回调函数
    
    /*显示窗帘图标*/
    smart_farm.control_obj.curtain = lv_label_create(control_bg, NULL);
    smart_farm.dialog_obj.curtain_dialog = NULL;
    lv_obj_set_pos(smart_farm.control_obj.curtain, 125, 150);
    lv_label_set_style(smart_farm.control_obj.curtain, LV_LABEL_STYLE_MAIN, &icon_style);
    lv_label_set_text(smart_farm.control_obj.curtain, CURTAIN);//设置文本
    lv_obj_set_click(smart_farm.control_obj.curtain, true);
    lv_obj_set_event_cb(smart_farm.control_obj.curtain, control_event_handler);//注册事件回调函数

    /*显示水泵图标*/
    smart_farm.control_obj.water = lv_label_create(control_bg, NULL);
    smart_farm.dialog_obj.water_dialog = NULL;
    lv_obj_set_pos(smart_farm.control_obj.water, 10, 50);
    lv_label_set_style(smart_farm.control_obj.water, LV_LABEL_STYLE_MAIN, &icon_style);
    lv_label_set_text(smart_farm.control_obj.water, WATER);//设置文本
    lv_obj_set_click(smart_farm.control_obj.water, true);
    lv_obj_set_event_cb(smart_farm.control_obj.water, control_event_handler);//注册事件回调函数

    /*显示LED图标*/

    smart_farm.control_obj.led = lv_label_create(control_bg, NULL);
    smart_farm.dialog_obj.led_dialog = NULL;
    lv_obj_set_pos(smart_farm.control_obj.led, 125, 50);
    lv_label_set_style(smart_farm.control_obj.led, LV_LABEL_STYLE_MAIN, &icon_style);
    lv_label_set_text(smart_farm.control_obj.led, LED);//设置文本
    lv_obj_set_click(smart_farm.control_obj.led, true);
    lv_obj_set_event_cb(smart_farm.control_obj.led, control_event_handler);//注册事件回调函数

    /*设置显示部分的字体样式*/
    static lv_style_t display_style;
    lv_style_copy(&display_style, &lv_style_plain_color);//样式拷贝
    display_style.text.font = &lv_font_roboto_16;//在样式中使用字体
    display_style.body.main_color = LV_COLOR_BLACK;
    display_style.body.grad_color = LV_COLOR_BLACK;
    display_style.text.color = LV_COLOR_WHITE;


    /*温度显示*/
    lv_style_copy(&smart_farm.display_obj.temp_main_style, &lv_style_plain_color);
    smart_farm.display_obj.temp_main_style.body.main_color = LV_COLOR_BLUE;//活跃刻度线的起始颜色
    smart_farm.display_obj.temp_main_style.body.grad_color = LV_COLOR_RED;//活跃刻度线的终止颜色
    smart_farm.display_obj.temp_main_style.line.color = LV_COLOR_SILVER;//非活跃刻度线的颜色
    smart_farm.display_obj.temp_main_style.line.width = 2;//每一条刻度线的宽度
    smart_farm.display_obj.temp_main_style.body.padding.left = 50;//每一条刻度线的长度

    smart_farm.display_obj.temp_lmeter = lv_lmeter_create(scr, NULL);
    lv_obj_set_size(smart_farm.display_obj.temp_lmeter, 220, 220);//设置大小
    lv_obj_set_pos(smart_farm.display_obj.temp_lmeter, 250, 5);
    lv_lmeter_set_range(smart_farm.display_obj.temp_lmeter, 0, 50);//设置进度范围
    lv_lmeter_set_value(smart_farm.display_obj.temp_lmeter, smart_farm.obj_value.temp_value);//设置当前的进度值
    lv_lmeter_set_scale(smart_farm.display_obj.temp_lmeter, 180, 30);//设置角度和刻度线的数量
    lv_lmeter_set_style(smart_farm.display_obj.temp_lmeter, LV_LMETER_STYLE_MAIN, &smart_farm.display_obj.temp_main_style);//设置样式


    smart_farm.display_obj.temp_num_label = lv_label_create(scr, NULL);
    lv_label_set_style(smart_farm.display_obj.temp_num_label, LV_LABEL_STYLE_MAIN, &display_style);//设置样式
    lv_obj_set_pos(smart_farm.display_obj.temp_num_label, 335, 120);
    lv_label_set_text(smart_farm.display_obj.temp_num_label, "temp:10%");//设
    lv_label_set_body_draw(smart_farm.display_obj.temp_num_label, true);//使能绘制背景
    lv_task_create(temp_task_cb, 500, LV_TASK_PRIO_MID, NULL);

    /*湿度显示*/
    lv_style_copy(&smart_farm.display_obj.humi_main_style, &lv_style_plain_color);
    smart_farm.display_obj.humi_main_style.body.main_color = LV_COLOR_BLUE;//活跃刻度线的起始颜色
    smart_farm.display_obj.humi_main_style.body.grad_color = LV_COLOR_RED;//活跃刻度线的终止颜色
    smart_farm.display_obj.humi_main_style.line.color = LV_COLOR_SILVER;//非活跃刻度线的颜色
    smart_farm.display_obj.humi_main_style.line.width = 2;//每一条刻度线的宽度
    smart_farm.display_obj.humi_main_style.body.padding.left = 50;//每一条刻度线的长度

    smart_farm.display_obj.humi_lmeter = lv_lmeter_create(scr, NULL);
    lv_obj_set_size(smart_farm.display_obj.humi_lmeter, 220, 220);//设置大小
    lv_obj_set_pos(smart_farm.display_obj.humi_lmeter, 530, 5);
    lv_lmeter_set_range(smart_farm.display_obj.humi_lmeter, 0, 100);//设置进度范围
    lv_lmeter_set_value(smart_farm.display_obj.humi_lmeter, smart_farm.obj_value.humi_value);//设置当前的进度值
    lv_lmeter_set_scale(smart_farm.display_obj.humi_lmeter, 180, 30);//设置角度和刻度线的数量
    lv_lmeter_set_style(smart_farm.display_obj.humi_lmeter, LV_LMETER_STYLE_MAIN, &smart_farm.display_obj.humi_main_style);//设置样式

    smart_farm.display_obj.humi_num_label = lv_label_create(scr, NULL);
    lv_label_set_style(smart_farm.display_obj.humi_num_label, LV_LABEL_STYLE_MAIN, &display_style);//设置样式
    lv_obj_set_pos(smart_farm.display_obj.humi_num_label, 610, 120);
    lv_label_set_text(smart_farm.display_obj.humi_num_label, "humi:10%");//设置文本
    lv_label_set_body_draw(smart_farm.display_obj.humi_num_label, true);//使能绘制背景
    lv_task_create(humi_task_cb, 500, LV_TASK_PRIO_MID, NULL);

    /*土壤湿度*/
    lv_style_copy(&smart_farm.display_obj.soil_main_style, &lv_style_plain_color);
    smart_farm.display_obj.soil_main_style.body.main_color = LV_COLOR_BLUE;//活跃刻度线的起始颜色
    smart_farm.display_obj.soil_main_style.body.grad_color = LV_COLOR_RED;//活跃刻度线的终止颜色
    smart_farm.display_obj.soil_main_style.line.color = LV_COLOR_SILVER;//非活跃刻度线的颜色
    smart_farm.display_obj.soil_main_style.line.width = 2;//每一条刻度线的宽度
    smart_farm.display_obj.soil_main_style.body.padding.left = 50;//每一条刻度线的长度

    smart_farm.display_obj.soil_lmeter = lv_lmeter_create(scr, NULL);
    lv_obj_set_size(smart_farm.display_obj.soil_lmeter, 220, 220);//设置大小
    lv_obj_set_pos(smart_farm.display_obj.soil_lmeter, 250, 165);
    lv_lmeter_set_range(smart_farm.display_obj.soil_lmeter, 0, 100);//设置进度范围
    lv_lmeter_set_value(smart_farm.display_obj.soil_lmeter, smart_farm.obj_value.soil_value);//设置当前的进度值
    lv_lmeter_set_scale(smart_farm.display_obj.soil_lmeter, 180, 30);//设置角度和刻度线的数量
    lv_lmeter_set_style(smart_farm.display_obj.soil_lmeter, LV_LMETER_STYLE_MAIN, &smart_farm.display_obj.soil_main_style);//设置样式

    smart_farm.display_obj.soil_num_label = lv_label_create(scr, NULL);
    lv_label_set_style(smart_farm.display_obj.soil_num_label, LV_LABEL_STYLE_MAIN, &display_style);//设置样式
    lv_obj_set_pos(smart_farm.display_obj.soil_num_label, 318, 295);
    lv_label_set_text(smart_farm.display_obj.soil_num_label, "soil_humi:10%");//设置文本
    lv_label_set_body_draw(smart_farm.display_obj.soil_num_label, true);//使能绘制背景
    lv_task_create(soil_task_cb, 500, LV_TASK_PRIO_MID, NULL);

    /*光照强度*/
    lv_style_copy(&smart_farm.display_obj.light_main_style, &lv_style_plain_color);
    smart_farm.display_obj.light_main_style.body.main_color = LV_COLOR_BLUE;//活跃刻度线的起始颜色
    smart_farm.display_obj.light_main_style.body.grad_color = LV_COLOR_RED;//活跃刻度线的终止颜色
    smart_farm.display_obj.light_main_style.line.color = LV_COLOR_SILVER;//非活跃刻度线的颜色
    smart_farm.display_obj.light_main_style.line.width = 2;//每一条刻度线的宽度
    smart_farm.display_obj.light_main_style.body.padding.left = 50;//每一条刻度线的长度

    smart_farm.display_obj.light_lmeter = lv_lmeter_create(scr, NULL);
    lv_obj_set_size(smart_farm.display_obj.light_lmeter, 220, 220);//设置大小
    lv_obj_set_pos(smart_farm.display_obj.light_lmeter, 530, 165);
    lv_lmeter_set_range(smart_farm.display_obj.light_lmeter, 0, 100);//设置进度范围
    lv_lmeter_set_value(smart_farm.display_obj.light_lmeter, smart_farm.obj_value.light_value);//设置当前的进度值
    lv_lmeter_set_scale(smart_farm.display_obj.light_lmeter, 180, 30);//设置角度和刻度线的数量
    lv_lmeter_set_style(smart_farm.display_obj.light_lmeter, LV_LMETER_STYLE_MAIN, &smart_farm.display_obj.light_main_style);//设置样式

    smart_farm.display_obj.light_num_label = lv_label_create(scr, NULL);
    lv_label_set_style(smart_farm.display_obj.light_num_label, LV_LABEL_STYLE_MAIN, &display_style);//设置样式
    lv_obj_set_pos(smart_farm.display_obj.light_num_label, 600, 295);
    lv_label_set_text(smart_farm.display_obj.light_num_label, "lighting:10%");//设置文本
    lv_label_set_body_draw(smart_farm.display_obj.light_num_label, true);//使能绘制背景
    lv_task_create(light_task_cb, 500, LV_TASK_PRIO_MID, NULL);

    /*co2浓度*/
    lv_style_copy(&smart_farm.display_obj.co2_main_style, &lv_style_plain_color);
    smart_farm.display_obj.co2_main_style.body.main_color = LV_COLOR_BLUE;//活跃刻度线的起始颜色
    smart_farm.display_obj.co2_main_style.body.grad_color = LV_COLOR_RED;//活跃刻度线的终止颜色
    smart_farm.display_obj.co2_main_style.line.color = LV_COLOR_SILVER;//非活跃刻度线的颜色
    smart_farm.display_obj.co2_main_style.line.width = 2;//每一条刻度线的宽度
    smart_farm.display_obj.co2_main_style.body.padding.left = 50;//每一条刻度线的长度

    smart_farm.display_obj.co2_lmeter = lv_lmeter_create(scr, NULL);
    lv_obj_set_size(smart_farm.display_obj.co2_lmeter, 220, 220);//设置大小
    lv_obj_set_pos(smart_farm.display_obj.co2_lmeter, 250, 330);
    lv_lmeter_set_range(smart_farm.display_obj.co2_lmeter, 0, 100);//设置进度范围
    lv_lmeter_set_value(smart_farm.display_obj.co2_lmeter, smart_farm.obj_value.co2_value);//设置当前的进度值
    lv_lmeter_set_scale(smart_farm.display_obj.co2_lmeter, 180, 30);//设置角度和刻度线的数量
    lv_lmeter_set_style(smart_farm.display_obj.co2_lmeter, LV_LMETER_STYLE_MAIN, &smart_farm.display_obj.co2_main_style);//设置样式


    smart_farm.display_obj.co2_num_label = lv_label_create(scr, NULL);
    lv_label_set_style(smart_farm.display_obj.co2_num_label, LV_LABEL_STYLE_MAIN, &display_style);//设置样式
    lv_obj_set_pos(smart_farm.display_obj.co2_num_label, 300, 450);
    lv_label_set_text(smart_farm.display_obj.co2_num_label, "  co2_value:1%");//设置文本
    lv_label_set_body_draw(smart_farm.display_obj.co2_num_label, true);//使能绘制背景
    lv_task_create(co2_task_cb, 500, LV_TASK_PRIO_MID, NULL);

    /*水箱剩余量*/
    lv_style_copy(&smart_farm.display_obj.water_main_style, &lv_style_plain_color);
    smart_farm.display_obj.water_main_style.body.main_color = LV_COLOR_BLUE;//活跃刻度线的起始颜色
    smart_farm.display_obj.water_main_style.body.grad_color = LV_COLOR_RED;//活跃刻度线的终止颜色
    smart_farm.display_obj.water_main_style.line.color = LV_COLOR_SILVER;//非活跃刻度线的颜色
    smart_farm.display_obj.water_main_style.line.width = 2;//每一条刻度线的宽度
    smart_farm.display_obj.water_main_style.body.padding.left = 50;//每一条刻度线的长度

    smart_farm.display_obj.water_lmeter = lv_lmeter_create(scr, NULL);
    lv_obj_set_size(smart_farm.display_obj.water_lmeter, 220, 220);//设置大小
    lv_obj_set_pos(smart_farm.display_obj.water_lmeter, 530, 330);
    lv_lmeter_set_range(smart_farm.display_obj.water_lmeter, 0, 100);//设置进度范围
    lv_lmeter_set_value(smart_farm.display_obj.water_lmeter, smart_farm.obj_value.water_value);//设置当前的进度值
    lv_lmeter_set_scale(smart_farm.display_obj.water_lmeter, 180, 30);//设置角度和刻度线的数量
    lv_lmeter_set_style(smart_farm.display_obj.water_lmeter, LV_LMETER_STYLE_MAIN, &smart_farm.display_obj.water_main_style);//设置样式

    smart_farm.display_obj.water_num_label = lv_label_create(scr, NULL);
    lv_label_set_style(smart_farm.display_obj.water_num_label, LV_LABEL_STYLE_MAIN, &display_style);//设置样式
    lv_obj_set_pos(smart_farm.display_obj.water_num_label, 585, 450);
    lv_label_set_text(smart_farm.display_obj.water_num_label, "water_allowance:0%");//设置文本
    lv_label_set_body_draw(smart_farm.display_obj.water_num_label, true);//使能绘制背景
    lv_task_create(water_task_cb, 500, LV_TASK_PRIO_MID, NULL);



}

/*日期回调函数*/
void update_date_cb(lv_task_t* task)
{
    //protocolTime_t *ptime = (protocolTime_t *)(uint8_t *)&gizwits.TimeNTP;
    char buff[30];
    //,ptime->month,ptime->day,ptime->hour,ptime->minute,ptime->second,ptime->ntp
    //sprintf(buff, "%0.4d-%0.2d-%0.2d",ptime->year,ptime->month,ptime->day);
    sprintf(buff, "%0.4d-%0.2d-%0.2d",time[0],time[1],time[2]);
	lv_label_set_text(smart_farm.time.date_text, buff);
}

/*时间回调函数*/
void update_time_cb(lv_task_t* task)
{
	//protocolTime_t *ptime = (protocolTime_t *)&gizwits.TimeNTP;
    char buff[20];
	sprintf(buff, "%0.2d:%0.2d",time[3],time[4]);
    //sprintf(buff, "%0.2d:%0.2d", smart_farm.obj_value.hour,smart_farm.obj_value.min);
    lv_label_set_text(smart_farm.time.time_text, buff);

}

/*温度回调函数*/
void temp_task_cb(lv_task_t* task)
{
    char buff[10];
    smart_farm.obj_value.temp_value = dht11_data.temp_int;
    lv_lmeter_set_value(smart_farm.display_obj.temp_lmeter, smart_farm.obj_value.temp_value);
    sprintf(buff, "temp:%0.2d%%", smart_farm.obj_value.temp_value);
    lv_label_set_text(smart_farm.display_obj.temp_num_label, buff);
}

void humi_task_cb(lv_task_t* task)
{
    char buff[10];
    lv_lmeter_set_value(smart_farm.display_obj.humi_lmeter, smart_farm.obj_value.humi_value);
    sprintf(buff, "humi:%0.2d%%", smart_farm.obj_value.humi_value);
    lv_label_set_text(smart_farm.display_obj.humi_num_label, buff);

}

void soil_task_cb(lv_task_t* task)
{
    char buff[20];
    lv_lmeter_set_value(smart_farm.display_obj.soil_lmeter, smart_farm.obj_value.soil_value);
    sprintf(buff, "soil_humi:%0.2d%%", smart_farm.obj_value.soil_value);
    lv_label_set_text(smart_farm.display_obj.soil_num_label, buff);

}

void light_task_cb(lv_task_t* task)
{
    char buff[20];
    lv_lmeter_set_value(smart_farm.display_obj.light_lmeter, smart_farm.obj_value.light_value);
    sprintf(buff, "lighting:%0.2d%%", smart_farm.obj_value.light_value);
    lv_label_set_text(smart_farm.display_obj.light_num_label , buff);

}

void co2_task_cb(lv_task_t* task)
{
    char buff[30];
    lv_lmeter_set_value(smart_farm.display_obj.co2_lmeter, smart_farm.obj_value.co2_value);
    sprintf(buff, "co2_value:%0.2d%%", smart_farm.obj_value.co2_value);
    lv_label_set_text(smart_farm.display_obj.co2_num_label, buff);

}

void water_task_cb(lv_task_t* task)
{
    char buff[20];
    lv_lmeter_set_value(smart_farm.display_obj.water_lmeter, smart_farm.obj_value.water_value);
    sprintf(buff, "water_allowance:%0.2d%%", smart_farm.obj_value.water_value);
    lv_label_set_text(smart_farm.display_obj.water_num_label, buff);

}





/*控制设备的回调函数*/
static void control_event_handler(lv_obj_t* obj, lv_event_t event)
{
    if (event == LV_EVENT_PRESSED || event == LV_EVENT_PRESS_LOST || event == LV_EVENT_RELEASED)
    {
        lv_style_t* style = (lv_style_t*)lv_label_get_style(obj, LV_LABEL_STYLE_MAIN);
        if (event == LV_EVENT_PRESSED)
        {
            style->body.radius = 10;
            style->body.opa = LV_OPA_50;

        }
        else
        {
            style->body.radius = 0;
            style->body.opa = LV_OPA_COVER;
        }

        lv_obj_refresh_style(obj);
    }

    if (obj == smart_farm.control_obj.fan)
    {
        if (event == LV_EVENT_RELEASED)
        {
            if (smart_farm.dialog_obj.fan_dialog == NULL)
            {
                smart_farm.dialog_obj.fan_dialog = fan_dialog_create(lv_scr_act());

            }
        }
    }
    else if (obj == smart_farm.dialog_obj.fan_cancel)
    {
        if (event == LV_EVENT_RELEASED || event == LV_EVENT_PRESS_LOST)
        {
            if (smart_farm.dialog_obj.fan_dialog)
            {
                lv_obj_del(smart_farm.dialog_obj.fan_dialog);
                smart_farm.dialog_obj.fan_dialog = NULL;
            }
        }
    }

    else if (obj == smart_farm.control_obj.curtain)
    {
        if (event == LV_EVENT_RELEASED)
        {
            if (smart_farm.dialog_obj.curtain_dialog == NULL)
            {
                smart_farm.dialog_obj.curtain_dialog = curtain_dialog_create(lv_scr_act());

            }
        }
    }
    else if (obj == smart_farm.dialog_obj.curtain_cancel)
    {
        if (event == LV_EVENT_RELEASED || event == LV_EVENT_PRESS_LOST)
        {
            if (smart_farm.dialog_obj.curtain_dialog)
            {
                lv_obj_del(smart_farm.dialog_obj.curtain_dialog);
                smart_farm.dialog_obj.curtain_dialog = NULL;
            }
        }
    }

    else if (obj == smart_farm.control_obj.water)
    {
        if (event == LV_EVENT_RELEASED)
        {
            if (smart_farm.dialog_obj.water_dialog == NULL)
            {
                smart_farm.dialog_obj.water_dialog = water_dialog_create(lv_scr_act());

            }
        }
    }
    else if (obj == smart_farm.dialog_obj.water_cancel)
    {
        if (event == LV_EVENT_RELEASED || event == LV_EVENT_PRESS_LOST)
        {
            if (smart_farm.dialog_obj.water_dialog)
            {
                lv_obj_del(smart_farm.dialog_obj.water_dialog);
                smart_farm.dialog_obj.water_dialog = NULL;
            }
        }
    }
    else if (obj == smart_farm.control_obj.led)
    {
        if (event == LV_EVENT_RELEASED)
        {
            if (smart_farm.dialog_obj.led_dialog == NULL)
            {
                smart_farm.dialog_obj.led_dialog = led_dialog_create(lv_scr_act());

            }
        }
    }
    else if (obj == smart_farm.dialog_obj.led_cancel)
    {
        if (event == LV_EVENT_RELEASED || event == LV_EVENT_PRESS_LOST)
        {
            if (smart_farm.dialog_obj.led_dialog)
            {
                lv_obj_del(smart_farm.dialog_obj.led_dialog);
                smart_farm.dialog_obj.led_dialog = NULL;
            }
        }
    }

}


lv_obj_t* fan_dialog_create(lv_obj_t* parent)
{

    lv_obj_t* gray_layer = lv_obj_create(parent, NULL);
    lv_obj_set_pos(gray_layer, 0, 0);
    lv_obj_set_size(gray_layer, 800, 480);
    static lv_style_t gray_layer_style;
    lv_style_copy(&gray_layer_style, &lv_style_plain_color);
    gray_layer_style.body.main_color = LV_COLOR_GRAY;
    gray_layer_style.body.grad_color = LV_COLOR_GRAY;
    gray_layer_style.body.opa = LV_OPA_80;
    lv_obj_set_style(gray_layer, &gray_layer_style);


    static lv_style_t btn_text_style;
    lv_style_copy(&btn_text_style, &lv_style_plain_color);
    btn_text_style.text.font = &time_font_80;
    btn_text_style.text.color = LV_COLOR_BLACK;

    lv_style_copy(&smart_farm.btn_status.my_style_btn_release, &lv_style_plain_color);
    //设置纯色的背景
    smart_farm.btn_status.my_style_btn_release.body.main_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    smart_farm.btn_status.my_style_btn_release.body.grad_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    smart_farm.btn_status.my_style_btn_release.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    smart_farm.btn_status.my_style_btn_release.body.radius = LV_RADIUS_CIRCLE;//绘制圆角按钮
    smart_farm.btn_status.my_style_btn_release.text.color = LV_COLOR_BLACK;

    //1.2 按下状态下的样式
    lv_style_copy(&smart_farm.btn_status.my_style_btn_press, &lv_style_plain_color);
    smart_farm.btn_status.my_style_btn_press.body.opa = LV_OPA_0;//设置背景色透明
    smart_farm.btn_status.my_style_btn_press.body.radius = LV_RADIUS_CIRCLE;//绘制圆角按钮
    //设置边框的颜色
    smart_farm.btn_status.my_style_btn_press.body.border.color = LV_COLOR_MAKE(0xd8, 0xbf, 0xd8);
    smart_farm.btn_status.my_style_btn_press.body.border.width = 2;//设置边框的宽度
    smart_farm.btn_status.my_style_btn_press.text.color = LV_COLOR_BLACK;

    lv_obj_t* top_bg = lv_obj_create(gray_layer, NULL);
    lv_obj_set_size(top_bg, DIALOG_WIDTH, DIALOG_HEIGTH);
    lv_obj_align(top_bg, gray_layer, LV_ALIGN_CENTER, 0, 0);
    static lv_style_t top_gb_style;
    lv_style_copy(&top_gb_style, &lv_style_plain_color);
    top_gb_style.body.main_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    top_gb_style.body.grad_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    top_gb_style.body.radius = 10;
    lv_obj_set_style(top_bg, &top_gb_style);

    lv_obj_t* fan_dialog_label = lv_label_create(top_bg, NULL);
    static lv_style_t fan_dialog_label_style;
    lv_style_copy(&fan_dialog_label_style, &lv_style_plain_color);
    fan_dialog_label_style.text.color = LV_COLOR_WHITE;
    fan_dialog_label_style.text.font = &lv_font_roboto_22;
    lv_label_set_style(fan_dialog_label, LV_LABEL_STYLE_MAIN, &fan_dialog_label_style);
    lv_label_set_text(fan_dialog_label, "Please choose wind speed\n          0 for shut down");
    lv_obj_align(fan_dialog_label, top_bg, LV_ALIGN_IN_TOP_MID, 0, 0);

    smart_farm.dialog_obj.fan_1 = lv_btn_create(top_bg, NULL);
    lv_obj_set_size(smart_farm.dialog_obj.fan_1, 105, 105);//设置大小
    lv_obj_set_pos(smart_farm.dialog_obj.fan_1, 215, 55);
    lv_btn_set_style(smart_farm.dialog_obj.fan_1, LV_BTN_STYLE_REL, &smart_farm.btn_status.my_style_btn_release);
    lv_btn_set_style(smart_farm.dialog_obj.fan_1, LV_BTN_STYLE_PR, &smart_farm.btn_status.my_style_btn_press);
    lv_obj_set_event_cb(smart_farm.dialog_obj.fan_1, fan_btn_cb);//设置按键事件回调

    lv_obj_t* fan_1_label = lv_label_create(smart_farm.dialog_obj.fan_1, NULL);
    lv_label_set_style(fan_1_label, LV_LABEL_STYLE_MAIN, &btn_text_style);
    lv_label_set_text(fan_1_label, "1");
    lv_obj_align(fan_1_label, smart_farm.dialog_obj.fan_1, LV_ALIGN_CENTER, 0, 0);

    smart_farm.dialog_obj.fan_2 = lv_btn_create(top_bg, NULL);
    lv_obj_set_size(smart_farm.dialog_obj.fan_2, 105, 105);//设置大小
    lv_obj_set_pos(smart_farm.dialog_obj.fan_2,85 , 180);
    lv_btn_set_style(smart_farm.dialog_obj.fan_2, LV_BTN_STYLE_REL, &smart_farm.btn_status.my_style_btn_release);
    lv_btn_set_style(smart_farm.dialog_obj.fan_2, LV_BTN_STYLE_PR, &smart_farm.btn_status.my_style_btn_press);
    lv_obj_set_event_cb(smart_farm.dialog_obj.fan_2, fan_btn_cb);//设置按键事件回调

    lv_obj_t* fan_2_label = lv_label_create(smart_farm.dialog_obj.fan_2, NULL);
    lv_label_set_style(fan_2_label, LV_LABEL_STYLE_MAIN, &btn_text_style);
    lv_label_set_text(fan_2_label, "2");
    lv_obj_align(fan_2_label, smart_farm.dialog_obj.fan_2, LV_ALIGN_CENTER, 0, 0);

    smart_farm.dialog_obj.fan_3 = lv_btn_create(top_bg, NULL);
    lv_obj_set_size(smart_farm.dialog_obj.fan_3, 105, 105);//设置大小
    lv_obj_set_pos(smart_farm.dialog_obj.fan_3, 215, 180);
    lv_btn_set_style(smart_farm.dialog_obj.fan_3, LV_BTN_STYLE_REL, &smart_farm.btn_status.my_style_btn_release);
    lv_btn_set_style(smart_farm.dialog_obj.fan_3, LV_BTN_STYLE_PR, &smart_farm.btn_status.my_style_btn_press);
    lv_obj_set_event_cb(smart_farm.dialog_obj.fan_3, fan_btn_cb);//设置按键事件回调

    lv_obj_t* fan_3_label = lv_label_create(smart_farm.dialog_obj.fan_3, NULL);
    lv_label_set_style(fan_3_label, LV_LABEL_STYLE_MAIN, &btn_text_style);
    lv_label_set_text(fan_3_label, "3");
    lv_obj_align(fan_3_label, smart_farm.dialog_obj.fan_3, LV_ALIGN_CENTER, 0, 0);

    smart_farm.dialog_obj.fan_0 = lv_btn_create(top_bg, NULL);
    lv_obj_set_size(smart_farm.dialog_obj.fan_0, 105, 105);//设置大小
    lv_obj_set_pos(smart_farm.dialog_obj.fan_0, 85, 55);
    lv_btn_set_style(smart_farm.dialog_obj.fan_0, LV_BTN_STYLE_REL, &smart_farm.btn_status.my_style_btn_release);
    lv_btn_set_style(smart_farm.dialog_obj.fan_0, LV_BTN_STYLE_PR, &smart_farm.btn_status.my_style_btn_press);
    lv_obj_set_event_cb(smart_farm.dialog_obj.fan_0, fan_btn_cb);//设置按键事件回调

    lv_obj_t* fan_0_label = lv_label_create(smart_farm.dialog_obj.fan_0, NULL);
    lv_label_set_style(fan_0_label, LV_LABEL_STYLE_MAIN, &btn_text_style);
    lv_label_set_text(fan_0_label, "0");
    lv_obj_align(fan_0_label, smart_farm.dialog_obj.fan_0, LV_ALIGN_CENTER, 0, 0);


    lv_obj_t* buttom_bg = lv_obj_create(gray_layer, NULL);
    lv_obj_set_size(buttom_bg, DIALOG_WIDTH, BUTTON_HEIGTH);
    lv_obj_align(buttom_bg, top_bg, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
    static lv_style_t buttom_bg_style;
    lv_style_copy(&buttom_bg_style, &lv_style_plain_color);
    buttom_bg_style.body.main_color = LV_COLOR_WHITE;
    buttom_bg_style.body.grad_color = LV_COLOR_WHITE;
    lv_obj_set_style(buttom_bg, &buttom_bg_style);


    smart_farm.dialog_obj.fan_cancel= lv_label_create(gray_layer, NULL);
    lv_label_set_long_mode(smart_farm.dialog_obj.fan_cancel, LV_LABEL_LONG_CROP);
    lv_obj_set_size(smart_farm.dialog_obj.fan_cancel, (DIALOG_WIDTH - DIALOG_BOTTOM_PADDING * 4) / 2, BUTTON_HEIGTH - DIALOG_BOTTOM_PADDING * 2);
    lv_label_set_style(smart_farm.dialog_obj.fan_cancel, LV_LABEL_STYLE_MAIN, &fan_dialog_label_style);
    lv_label_set_text(smart_farm.dialog_obj.fan_cancel, "cancel");
    lv_label_set_align(smart_farm.dialog_obj.fan_cancel, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(smart_farm.dialog_obj.fan_cancel, buttom_bg, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_body_draw(smart_farm.dialog_obj.fan_cancel, true);

    static lv_style_t fan_cancel_style;
    lv_style_copy(&fan_cancel_style, &lv_style_plain_color);
    fan_cancel_style.body.main_color = LV_COLOR_WHITE;
    fan_cancel_style.body.grad_color = LV_COLOR_WHITE;
    fan_cancel_style.body.border.width = 1;
    fan_cancel_style.body.border.color = LV_COLOR_MAKE(0xBD, 0xBA, 0xBD);
    fan_cancel_style.body.border.part = LV_BORDER_FULL;
    fan_cancel_style.text.color = LV_COLOR_MAKE(0x63, 0x65, 0x63);
    fan_cancel_style.text.font = &S_dialog_text_font1;
    lv_label_set_style(smart_farm.dialog_obj.fan_cancel, LV_LABEL_STYLE_MAIN, &fan_cancel_style);
    lv_obj_set_click(smart_farm.dialog_obj.fan_cancel, true);//使能点击
    lv_obj_set_event_cb(smart_farm.dialog_obj.fan_cancel, control_event_handler);//注册事件回调函数

    return gray_layer;
}

lv_obj_t* curtain_dialog_create(lv_obj_t* parent)
{

    lv_obj_t* gray_layer = lv_obj_create(parent, NULL);
    lv_obj_set_pos(gray_layer, 0, 0);
    lv_obj_set_size(gray_layer, 800, 480);
    static lv_style_t gray_layer_style;
    lv_style_copy(&gray_layer_style, &lv_style_plain_color);
    gray_layer_style.body.main_color = LV_COLOR_GRAY;
    gray_layer_style.body.grad_color = LV_COLOR_GRAY;
    gray_layer_style.body.opa = LV_OPA_80;
    lv_obj_set_style(gray_layer, &gray_layer_style);


    static lv_style_t btn_text_style;
    lv_style_copy(&btn_text_style, &lv_style_plain_color);
    btn_text_style.text.font = &time_font_80;
    btn_text_style.text.color = LV_COLOR_BLACK;

    lv_style_copy(&smart_farm.btn_status.my_style_btn_release, &lv_style_plain_color);
    //设置纯色的背景
    smart_farm.btn_status.my_style_btn_release.body.main_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    smart_farm.btn_status.my_style_btn_release.body.grad_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    smart_farm.btn_status.my_style_btn_release.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    smart_farm.btn_status.my_style_btn_release.body.radius = LV_RADIUS_CIRCLE;//绘制圆角按钮
    smart_farm.btn_status.my_style_btn_release.text.color = LV_COLOR_BLACK;

    //1.2 按下状态下的样式
    lv_style_copy(&smart_farm.btn_status.my_style_btn_press, &lv_style_plain_color);
    smart_farm.btn_status.my_style_btn_press.body.opa = LV_OPA_0;//设置背景色透明
    smart_farm.btn_status.my_style_btn_press.body.radius = LV_RADIUS_CIRCLE;//绘制圆角按钮
    //设置边框的颜色
    smart_farm.btn_status.my_style_btn_press.body.border.color = LV_COLOR_MAKE(0xd8, 0xbf, 0xd8);
    smart_farm.btn_status.my_style_btn_press.body.border.width = 2;//设置边框的宽度
    smart_farm.btn_status.my_style_btn_press.text.color = LV_COLOR_BLACK;

    lv_obj_t* top_bg = lv_obj_create(gray_layer, NULL);
    lv_obj_set_size(top_bg, DIALOG_WIDTH, 250);
    lv_obj_align(top_bg, gray_layer, LV_ALIGN_CENTER, 0, 0);
    static lv_style_t top_gb_style;
    lv_style_copy(&top_gb_style, &lv_style_plain_color);
    top_gb_style.body.main_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    top_gb_style.body.grad_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    top_gb_style.body.radius = 10;
    lv_obj_set_style(top_bg, &top_gb_style);

    lv_obj_t* curtain_dialog_label = lv_label_create(top_bg, NULL);
    static lv_style_t curtain_dialog_label_style;
    lv_style_copy(&curtain_dialog_label_style, &lv_style_plain_color);
    curtain_dialog_label_style.text.color = LV_COLOR_WHITE;
    curtain_dialog_label_style.text.font = &lv_font_roboto_22;
    lv_label_set_style(curtain_dialog_label, LV_LABEL_STYLE_MAIN, &curtain_dialog_label_style);
    lv_label_set_text(curtain_dialog_label, "Please Select Curtain Status\n   0 to close and 1 to open");
    lv_obj_align(curtain_dialog_label, top_bg, LV_ALIGN_IN_TOP_MID, 0, 0);

    smart_farm.dialog_obj.curtain_on = lv_btn_create(top_bg, NULL);
    lv_obj_set_size(smart_farm.dialog_obj.curtain_on, 120, 120);//设置大小
    lv_obj_set_pos(smart_farm.dialog_obj.curtain_on, 210, 60);
    lv_btn_set_style(smart_farm.dialog_obj.curtain_on, LV_BTN_STYLE_REL, &smart_farm.btn_status.my_style_btn_release);
    lv_btn_set_style(smart_farm.dialog_obj.curtain_on, LV_BTN_STYLE_PR, &smart_farm.btn_status.my_style_btn_press);
    lv_obj_set_event_cb(smart_farm.dialog_obj.curtain_on, curtain_btn_cb);//设置 btn2 的事件回调

    lv_obj_t* curtain_on_label = lv_label_create(smart_farm.dialog_obj.curtain_on, NULL);

    lv_label_set_style(curtain_on_label, LV_LABEL_STYLE_MAIN, &btn_text_style);
    lv_label_set_text(curtain_on_label, "1");
    lv_obj_align(curtain_on_label, smart_farm.dialog_obj.curtain_on, LV_ALIGN_CENTER, 0, 0);


    smart_farm.dialog_obj.curtain_off = lv_btn_create(top_bg, NULL);
    lv_obj_set_size(smart_farm.dialog_obj.curtain_off, 120, 120);//设置大小
    lv_obj_set_pos(smart_farm.dialog_obj.curtain_off,65, 60);
    lv_btn_set_style(smart_farm.dialog_obj.curtain_off, LV_BTN_STYLE_REL, &smart_farm.btn_status.my_style_btn_release);
    lv_btn_set_style(smart_farm.dialog_obj.curtain_off, LV_BTN_STYLE_PR, &smart_farm.btn_status.my_style_btn_press);
    lv_obj_set_event_cb(smart_farm.dialog_obj.curtain_off, curtain_btn_cb);//设置 btn2 的事件回调

    lv_obj_t* curtain_off_label = lv_label_create(smart_farm.dialog_obj.curtain_off, NULL);

    lv_label_set_style(curtain_off_label, LV_LABEL_STYLE_MAIN, &btn_text_style);
    lv_label_set_text(curtain_off_label, "0");
    lv_obj_align(curtain_off_label, smart_farm.dialog_obj.curtain_off, LV_ALIGN_CENTER, 0, 0);


    lv_obj_t* buttom_bg = lv_obj_create(gray_layer, NULL);
    lv_obj_set_size(buttom_bg, DIALOG_WIDTH, BUTTON_HEIGTH);
    lv_obj_align(buttom_bg, top_bg, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
    static lv_style_t buttom_bg_style;
    lv_style_copy(&buttom_bg_style, &lv_style_plain_color);
    buttom_bg_style.body.main_color = LV_COLOR_WHITE;
    buttom_bg_style.body.grad_color = LV_COLOR_WHITE;
    lv_obj_set_style(buttom_bg, &buttom_bg_style);


    smart_farm.dialog_obj.curtain_cancel = lv_label_create(gray_layer, NULL);
    lv_label_set_long_mode(smart_farm.dialog_obj.curtain_cancel, LV_LABEL_LONG_CROP);
    lv_obj_set_size(smart_farm.dialog_obj.curtain_cancel, (DIALOG_WIDTH - DIALOG_BOTTOM_PADDING * 4) / 2, BUTTON_HEIGTH - DIALOG_BOTTOM_PADDING * 2);
    lv_label_set_style(smart_farm.dialog_obj.curtain_cancel, LV_LABEL_STYLE_MAIN, &curtain_dialog_label_style);
    lv_label_set_text(smart_farm.dialog_obj.curtain_cancel, "cancel");
    lv_label_set_align(smart_farm.dialog_obj.curtain_cancel, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(smart_farm.dialog_obj.curtain_cancel, buttom_bg, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_body_draw(smart_farm.dialog_obj.curtain_cancel, true);

    static lv_style_t curtain_cancel_style;
    lv_style_copy(&curtain_cancel_style, &lv_style_plain_color);
    curtain_cancel_style.body.main_color = LV_COLOR_WHITE;
    curtain_cancel_style.body.grad_color = LV_COLOR_WHITE;
    curtain_cancel_style.body.border.width = 1;
    curtain_cancel_style.body.border.color = LV_COLOR_MAKE(0xBD, 0xBA, 0xBD);
    curtain_cancel_style.body.border.part = LV_BORDER_FULL;
    curtain_cancel_style.text.color = LV_COLOR_MAKE(0x63, 0x65, 0x63);
    curtain_cancel_style.text.font = &S_dialog_text_font1;
    lv_label_set_style(smart_farm.dialog_obj.curtain_cancel, LV_LABEL_STYLE_MAIN, &curtain_cancel_style);
    lv_obj_set_click(smart_farm.dialog_obj.curtain_cancel, true);//使能点击
    lv_obj_set_event_cb(smart_farm.dialog_obj.curtain_cancel, control_event_handler);//注册事件回调函数

    return gray_layer;
}

lv_obj_t* water_dialog_create(lv_obj_t* parent)
{

    lv_obj_t* gray_layer = lv_obj_create(parent, NULL);
    lv_obj_set_pos(gray_layer, 0, 0);
    lv_obj_set_size(gray_layer, 800, 480);
    static lv_style_t gray_layer_style;
    lv_style_copy(&gray_layer_style, &lv_style_plain_color);
    gray_layer_style.body.main_color = LV_COLOR_GRAY;
    gray_layer_style.body.grad_color = LV_COLOR_GRAY;
    gray_layer_style.body.opa = LV_OPA_80;
    lv_obj_set_style(gray_layer, &gray_layer_style);

    static lv_style_t btn_text_style;
    lv_style_copy(&btn_text_style, &lv_style_plain_color);
    btn_text_style.text.font = &time_font_80;
    btn_text_style.text.color = LV_COLOR_BLACK;

    lv_style_copy(&smart_farm.btn_status.my_style_btn_release, &lv_style_plain_color);
    //设置纯色的背景
    smart_farm.btn_status.my_style_btn_release.body.main_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    smart_farm.btn_status.my_style_btn_release.body.grad_color = LV_COLOR_MAKE(0x2F, 0x2f, 0x4f);
    smart_farm.btn_status.my_style_btn_release.body.opa = LV_OPA_COVER;//设置背景色完全不透明
    smart_farm.btn_status.my_style_btn_release.body.radius = LV_RADIUS_CIRCLE;//绘制圆角按钮
    smart_farm.btn_status.my_style_btn_release.text.color = LV_COLOR_BLACK;

    //1.2 按下状态下的样式
    lv_style_copy(&smart_farm.btn_status.my_style_btn_press, &lv_style_plain_color);
    smart_farm.btn_status.my_style_btn_press.body.opa = LV_OPA_0;//设置背景色透明
    smart_farm.btn_status.my_style_btn_press.body.radius = LV_RADIUS_CIRCLE;//绘制圆角按钮
    //设置边框的颜色
    smart_farm.btn_status.my_style_btn_press.body.border.color = LV_COLOR_MAKE(0xd8, 0xbf, 0xd8);
    smart_farm.btn_status.my_style_btn_press.body.border.width = 2;//设置边框的宽度
    smart_farm.btn_status.my_style_btn_press.text.color = LV_COLOR_BLACK;

    lv_obj_t* top_bg = lv_obj_create(gray_layer, NULL);
    lv_obj_set_size(top_bg, DIALOG_WIDTH, 250);
    lv_obj_align(top_bg, gray_layer, LV_ALIGN_CENTER, 0, 0);
    static lv_style_t top_gb_style;
    lv_style_copy(&top_gb_style, &lv_style_plain_color);
    top_gb_style.body.main_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    top_gb_style.body.grad_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    top_gb_style.body.radius = 10;
    lv_obj_set_style(top_bg, &top_gb_style);

    lv_obj_t* water_dialog_label = lv_label_create(top_bg, NULL);
    static lv_style_t water_dialog_label_style;
    lv_style_copy(&water_dialog_label_style, &lv_style_plain_color);
    water_dialog_label_style.text.color = LV_COLOR_WHITE;
    water_dialog_label_style.text.font = &lv_font_roboto_22;
    lv_label_set_style(water_dialog_label, LV_LABEL_STYLE_MAIN, &water_dialog_label_style);
    lv_label_set_text(water_dialog_label, "Please choose whether to water or not\n           0 to close and 1 to open");
    lv_obj_align(water_dialog_label, top_bg, LV_ALIGN_IN_TOP_MID, 0, 0);

    smart_farm.dialog_obj.water_on = lv_btn_create(top_bg, NULL);
    lv_obj_set_size(smart_farm.dialog_obj.water_on, 120, 120);//设置大小
    lv_obj_set_pos(smart_farm.dialog_obj.water_on, 65, 60);
    lv_btn_set_style(smart_farm.dialog_obj.water_on, LV_BTN_STYLE_REL, &smart_farm.btn_status.my_style_btn_release);
    lv_btn_set_style(smart_farm.dialog_obj.water_on, LV_BTN_STYLE_PR, &smart_farm.btn_status.my_style_btn_press);
    lv_obj_set_event_cb(smart_farm.dialog_obj.water_on, water_btn_cb);

    lv_obj_t* water_on_label = lv_label_create(smart_farm.dialog_obj.water_on, NULL);

    lv_label_set_style(water_on_label, LV_LABEL_STYLE_MAIN, &btn_text_style);
    lv_label_set_text(water_on_label, "0");
    lv_obj_align(water_on_label, smart_farm.dialog_obj.water_on, LV_ALIGN_CENTER, 0, 0);

    smart_farm.dialog_obj.water_off = lv_btn_create(top_bg, NULL);
    lv_obj_set_size(smart_farm.dialog_obj.water_off, 120, 120);//设置大小
    lv_obj_set_pos(smart_farm.dialog_obj.water_off, 210, 60);
    lv_btn_set_style(smart_farm.dialog_obj.water_off, LV_BTN_STYLE_REL, &smart_farm.btn_status.my_style_btn_release);
    lv_btn_set_style(smart_farm.dialog_obj.water_off, LV_BTN_STYLE_PR, &smart_farm.btn_status.my_style_btn_press);
    lv_obj_set_event_cb(smart_farm.dialog_obj.water_off, water_btn_cb);

    lv_obj_t* water_off_label = lv_label_create(smart_farm.dialog_obj.water_off, NULL);

    lv_label_set_style(water_off_label, LV_LABEL_STYLE_MAIN, &btn_text_style);
    lv_label_set_text(water_off_label, "1");
    lv_obj_align(water_off_label, smart_farm.dialog_obj.water_off, LV_ALIGN_CENTER, 0, 0);


    lv_obj_t* buttom_bg = lv_obj_create(gray_layer, NULL);
    lv_obj_set_size(buttom_bg, DIALOG_WIDTH, BUTTON_HEIGTH);
    lv_obj_align(buttom_bg, top_bg, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
    static lv_style_t buttom_bg_style;
    lv_style_copy(&buttom_bg_style, &lv_style_plain_color);
    buttom_bg_style.body.main_color = LV_COLOR_WHITE;
    buttom_bg_style.body.grad_color = LV_COLOR_WHITE;
    lv_obj_set_style(buttom_bg, &buttom_bg_style);


    smart_farm.dialog_obj.water_cancel = lv_label_create(gray_layer, NULL);
    lv_label_set_long_mode(smart_farm.dialog_obj.water_cancel, LV_LABEL_LONG_CROP);
    lv_obj_set_size(smart_farm.dialog_obj.water_cancel, (DIALOG_WIDTH - DIALOG_BOTTOM_PADDING * 4) / 2, BUTTON_HEIGTH - DIALOG_BOTTOM_PADDING * 2);
    lv_label_set_style(smart_farm.dialog_obj.water_cancel, LV_LABEL_STYLE_MAIN, &water_dialog_label_style);
    lv_label_set_text(smart_farm.dialog_obj.water_cancel, "cancel");
    lv_label_set_align(smart_farm.dialog_obj.water_cancel, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(smart_farm.dialog_obj.water_cancel, buttom_bg, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_body_draw(smart_farm.dialog_obj.water_cancel, true);

    static lv_style_t water_cancel_style;
    lv_style_copy(&water_cancel_style, &lv_style_plain_color);
    water_cancel_style.body.main_color = LV_COLOR_WHITE;
    water_cancel_style.body.grad_color = LV_COLOR_WHITE;
    water_cancel_style.body.border.width = 1;
    water_cancel_style.body.border.color = LV_COLOR_MAKE(0xBD, 0xBA, 0xBD);
    water_cancel_style.body.border.part = LV_BORDER_FULL;
    water_cancel_style.text.color = LV_COLOR_MAKE(0x63, 0x65, 0x63);
    water_cancel_style.text.font = &S_dialog_text_font1;
    lv_label_set_style(smart_farm.dialog_obj.water_cancel, LV_LABEL_STYLE_MAIN, &water_cancel_style);
    lv_obj_set_click(smart_farm.dialog_obj.water_cancel, true);//使能点击
    lv_obj_set_event_cb(smart_farm.dialog_obj.water_cancel, control_event_handler);//注册事件回调函数

    return gray_layer;
}


lv_obj_t* led_dialog_create(lv_obj_t* parent)
{

    lv_obj_t* gray_layer = lv_obj_create(parent, NULL);
    lv_obj_set_pos(gray_layer, 0, 0);
    lv_obj_set_size(gray_layer, 800, 480);
    static lv_style_t gray_layer_style;
    lv_style_copy(&gray_layer_style, &lv_style_plain_color);
    gray_layer_style.body.main_color = LV_COLOR_GRAY;
    gray_layer_style.body.grad_color = LV_COLOR_GRAY;
    gray_layer_style.body.opa = LV_OPA_60;
    lv_obj_set_style(gray_layer, &gray_layer_style);


    lv_obj_t* top_bg = lv_obj_create(gray_layer, NULL);
    lv_obj_set_size(top_bg, DIALOG_WIDTH, 250);
    lv_obj_align(top_bg, gray_layer, LV_ALIGN_CENTER, 0, 0);
    static lv_style_t top_gb_style;
    lv_style_copy(&top_gb_style, &lv_style_plain_color);
    top_gb_style.body.main_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    top_gb_style.body.grad_color = LV_COLOR_MAKE(0x1A, 0x1A, 0x1A);
    top_gb_style.body.radius = 10;
    lv_obj_set_style(top_bg, &top_gb_style);

    lv_obj_t* led_dialog_label = lv_label_create(top_bg, NULL);
    static lv_style_t led_dialog_label_style;
    lv_style_copy(&led_dialog_label_style, &lv_style_plain_color);
    led_dialog_label_style.text.color = LV_COLOR_WHITE;
    led_dialog_label_style.text.font = &lv_font_roboto_22;
    lv_label_set_style(led_dialog_label, LV_LABEL_STYLE_MAIN, &led_dialog_label_style);
    lv_label_set_text(led_dialog_label, "Please select the brightness of the lamp");
    lv_obj_align(led_dialog_label, top_bg, LV_ALIGN_IN_TOP_MID, 0, 0);

    static lv_style_t led_style_bg;
    static lv_style_t led_style_indic;
    static lv_style_t led_style_knob;

    lv_style_copy(&led_style_bg, &lv_style_pretty);
    led_style_bg.body.main_color = LV_COLOR_BLACK;
    led_style_bg.body.grad_color = LV_COLOR_GRAY;
    led_style_bg.body.radius = LV_RADIUS_CIRCLE;
    led_style_bg.body.border.color = LV_COLOR_WHITE;

    lv_style_copy(&led_style_indic, &lv_style_pretty_color);
    led_style_indic.body.radius = LV_RADIUS_CIRCLE;
    led_style_indic.body.shadow.width = 8;
    led_style_indic.body.shadow.color = led_style_indic.body.main_color;
    led_style_indic.body.padding.left = 3;
    led_style_indic.body.padding.right = 3;
    led_style_indic.body.padding.top = 3;
    led_style_indic.body.padding.bottom = 3;

    lv_style_copy(&led_style_knob, &lv_style_pretty);
    led_style_knob.body.radius = LV_RADIUS_CIRCLE;
    led_style_knob.body.opa = LV_OPA_70;
    led_style_knob.body.padding.top = 10;
    led_style_knob.body.padding.bottom = 10;

    lv_obj_t* led_slider = lv_slider_create(top_bg, NULL);
    lv_obj_set_size(led_slider, 260, 40);
    lv_slider_set_style(led_slider, LV_SLIDER_STYLE_BG, &led_style_bg);
    lv_slider_set_style(led_slider, LV_SLIDER_STYLE_INDIC, &led_style_indic);
    lv_slider_set_style(led_slider, LV_SLIDER_STYLE_KNOB, &led_style_knob);
    //lv_obj_align(led_slider, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_pos(led_slider, 80, 80);
    lv_slider_set_range(led_slider, 0, 100);
    lv_obj_set_event_cb(led_slider, led_event_handler);

    smart_farm.dialog_obj.led_label = lv_label_create(top_bg, NULL);
    static lv_style_t led_label_style;
    lv_style_copy(&led_label_style, &lv_style_plain_color);//样式拷贝
    led_label_style.text.font = &date_font_24;//在样式中使用字体
    led_label_style.text.color = LV_COLOR_WHITE;
    lv_label_set_style(smart_farm.dialog_obj.led_label, LV_LABEL_STYLE_MAIN, &led_label_style);
    lv_label_set_text(smart_farm.dialog_obj.led_label, "000");
    lv_obj_set_pos(smart_farm.dialog_obj.led_label, 190, 145);
    //lv_obj_set_auto_realign(led_label, true);


    lv_obj_t* buttom_bg = lv_obj_create(gray_layer, NULL);
    lv_obj_set_size(buttom_bg, DIALOG_WIDTH, BUTTON_HEIGTH);
    lv_obj_align(buttom_bg, top_bg, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
    static lv_style_t buttom_bg_style;
    lv_style_copy(&buttom_bg_style, &lv_style_plain_color);
    buttom_bg_style.body.main_color = LV_COLOR_WHITE;
    buttom_bg_style.body.grad_color = LV_COLOR_WHITE;
    lv_obj_set_style(buttom_bg, &buttom_bg_style);


    smart_farm.dialog_obj.led_cancel = lv_label_create(gray_layer, NULL);
    lv_label_set_long_mode(smart_farm.dialog_obj.led_cancel, LV_LABEL_LONG_CROP);
    lv_obj_set_size(smart_farm.dialog_obj.led_cancel, (DIALOG_WIDTH - DIALOG_BOTTOM_PADDING * 4) / 2, BUTTON_HEIGTH - DIALOG_BOTTOM_PADDING * 2);
    lv_label_set_style(smart_farm.dialog_obj.led_cancel, LV_LABEL_STYLE_MAIN, &led_dialog_label_style);
    lv_label_set_text(smart_farm.dialog_obj.led_cancel, "cancel");
    lv_label_set_align(smart_farm.dialog_obj.led_cancel, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(smart_farm.dialog_obj.led_cancel, buttom_bg, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_body_draw(smart_farm.dialog_obj.led_cancel, true);

    static lv_style_t led_cancel_style;
    lv_style_copy(&led_cancel_style, &lv_style_plain_color);
    led_cancel_style.body.main_color = LV_COLOR_WHITE;
    led_cancel_style.body.border.width = 1;
    led_cancel_style.body.border.color = LV_COLOR_MAKE(0xBD, 0xBA, 0xBD);
    led_cancel_style.body.border.part = LV_BORDER_FULL;
    led_cancel_style.text.color = LV_COLOR_MAKE(0x63, 0x65, 0x63);
    led_cancel_style.text.font = &S_dialog_text_font1;
    lv_label_set_style(smart_farm.dialog_obj.led_cancel, LV_LABEL_STYLE_MAIN, &led_cancel_style);
    lv_obj_set_click(smart_farm.dialog_obj.led_cancel, true);//使能点击
    lv_obj_set_event_cb(smart_farm.dialog_obj.led_cancel, control_event_handler);//注册事件回调函数

    return gray_layer;
}






static void fan_btn_cb(lv_obj_t* obj, lv_event_t event)
{
    if (event == LV_EVENT_RELEASED)
    {
        if (obj == smart_farm.dialog_obj.fan_0)
        {

        }
        else if (obj == smart_farm.dialog_obj.fan_1)
        {

        }
        else if (obj == smart_farm.dialog_obj.fan_2)
        {

        }
        else if (obj == smart_farm.dialog_obj.fan_3)
        {

        }
    }
}

static void curtain_btn_cb(lv_obj_t* obj, lv_event_t event)
{
    if (event == LV_EVENT_RELEASED)
    {
        if (obj == smart_farm.dialog_obj.curtain_on)
        {

        }
        else if (obj == smart_farm.dialog_obj.curtain_off)
        {

        }
    }
}

static void water_btn_cb(lv_obj_t* obj, lv_event_t event)
{
    if (event == LV_EVENT_RELEASED)
    {
        if (obj == smart_farm.dialog_obj.water_on)
        {

        }
        else if (obj == smart_farm.dialog_obj.water_off)
        {

        }
    }
}


static void led_event_handler(lv_obj_t* slider, lv_event_t event)
{
    if (event == LV_EVENT_VALUE_CHANGED) {
        static char buff[10];
        sprintf(buff, "%0.3d", lv_slider_get_value(slider));
        lv_label_set_text(smart_farm.dialog_obj.led_label, buff);
        /*light_value = lv_slider_get_value(slider);*/
    }
}
