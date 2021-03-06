 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("花满城", ({ "huaman" }) );
        set("gender", "男性" );
        set("age", 81);
        set("title", BLU "月老"NOR);
        set("long",
                "这位老板正对你露出慈祥的笑容。\n");
        set("combat_exp", 350000);
        set("attitude", "friendly");
        set("per",20);
        set("vendor_goods", ([
                __DIR__"obj/purple_flower":30,
                __DIR__"obj/red_flower":25,
                __DIR__"obj/yellow_flower":33,
                __DIR__"obj/blue_flower":44,
                __DIR__"obj/white_flower":14,
                __DIR__"obj/black_flower":10,
        ]) );
        set_skill("unarmed",50);
        set_skill("dodge",50);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
} 
void init()
{       
        add_action("assign_delivery","deliver");        
} 
mapping *delivery = ({
        ([      "flowersender":                "李寻欢",
                "floweraccepter":           "孙小红",
        ]),
});
//Find the First Index to have exp level >= x 
mapping query_delivery()
{
        int i;
   i = 0;
  return delivery[i];
} 
string get_flower()
{
        mapping goods;
        int i;
        string *names;
        goods = query("vendor_goods");
        names = keys(goods);
        i = sizeof(names);
        //write( names[random(i)]);
        return names[random(i)];
} 
int assign_delivery()
{
        mapping delivery;
    string dstr;
        object who;
        object flower;
    who = this_player();
        /*
        if((quest =  who->query("quest")) && (time() - who->query("task_time") < 900)) {
                return 0;d
        }
        
        if((who->query("next_time")) > time()) {
                return notify_fail(HIW"你要过" 
                                + wait_period(who->query("next_time") - time()) 
                                + "之后才可要任务。\n"NOR);
        }
        
        combatexp = (int)who->query("combat_exp");
        if(combatexp/1024 < 100) {
          tag="_small";
        } else if(combatexp/1024 < 1000) {
          tag="_middle";
        } else {
          tag="_large";
        }
           
        quest = QUEST_D(tag)->query_quest(combatexp/1000);*/
        flower = new(get_flower());
        flower->move(who);
        delivery = query_delivery();
        who->set("delivery", delivery);
        who->set("delivery_time", (int)time());
        who->add_temp("delivery_number", 1);
        
        
        dstr = HIW"替『" + delivery["flowersender"] + HIW"』把"+ flower->name() + "给" 
                                + delivery["floweraccepter"] + HIW"送过去。"NOR; 
        
        tell_object(who,  this_object()->name() + HIW"说道：请" + dstr + "\n");
        /*
        CHANNEL_D->do_sys_channel("qst", sprintf("%s让%s(%s)%s\n",
                me["name"],
                HIW + who->name(),
                HIW + who->query("id"),
                HIW + qstr));
        */
        return 1;
}    
