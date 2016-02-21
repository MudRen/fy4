#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("age",30+random(20));
        set("attitude", "aggressive");
        set("combat_exp", 5500000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 3000);
        set("atman", 3000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",80);
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
        
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",250,200,0,"/d/eren2/npc/obj/","fighter_u","yue-strike");
        set_name("�������",({"heimian"}));
           set("title",HIG"ʮ������"NOR);
        set("long", "��ʮ�������еġ���������������������ߣ���С�ݸɣ�ȴ����һ
���������ѣ���ģ������˵�����Ĺ��أ�˵�������������\n");
        
        setup();
        carry_object(__DIR__"obj/j_cloth")->wear();
}  
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() ) return;
        message_vision(CYN"$N��������˵���ߺߣ�����\n"NOR,this_object());
}  