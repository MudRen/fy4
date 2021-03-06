 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int yuefei();
int leave();
void create()
{
    set_name("殷正廉", ({ "master yin", "master","yin" }) );
    set("long",
        "济南城中最高的官，有至高无上的权力\n");
    set("nickname", RED"龙图阁大学士"NOR);
    set("class","official");
    set("attitude", "heroism");
    set("reward_npc", 1);
        set("difficulty", 35);
        set("chat_chance", 1);
        set("chat_msg", ({
                "殷正廉道：皇上当年赐给我的尚方宝剑不见了。。。\n",
                "殷正廉摇摇头道：宝剑不见了，没有心情教学生。。。\n",
        }) );
    // Make this before create_family will prevent generation in title
    set("rank_nogen",1);
    create_family("朝廷命官",6,"太子太保 守济南府");
    set("student_title","官员");
    set("ranks",({ "准备将","副将","正将","副统领","统领","御营副统制",
                       "御营统制","御营都统制","龙神卫四厢都指挥使","捧日天武四厢都指挥使",
                       "侍卫亲军步军都虞候","侍卫亲军马军都虞候",RED"殿前都虞候"NOR,
                       CYN"侍卫亲军步军副指挥使"NOR,YEL"侍卫亲军马军副指挥使"NOR,BLU"殿前副指挥使"NOR,
                       CYN"侍卫亲军步军都指挥使"NOR,YEL"侍卫亲军马军都指挥使"NOR,RED"殿前都指挥使"NOR }));
    set("rank_levels",({ 32000,64000,128000,256000,384000,
                             512000,800000,1024000,1556000,
                             2048000,3652000,5000000,
                             6258000,8848000,10800000,
                             14580000,20048000,26244000 })); 
        set("inquiry", ([
                "zonghengtianxia" : (: yuefei :),
                "纵横天下" : (: yuefei :),
           "yuefei" : (: yuefei :),
                "岳飞" : (: yuefei :),
                "leave" : (: leave :),
        ]));
    set("vendetta_mark", "authority");
    set("str", 50+random(10));
    set("cor", 40);
    set("cps", 25);
    set("agi",25);
    set("int",30);
/*    set("max_kee",7000);
    set("max_gin",5000);
    set("max_sen",5000); */
    set("max_force",2000);
    set("force",2000);
    set("eff_force",2000);
        set("age",55);
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yuhuan" :),
            }) );
    set("combat_exp", 90000000);
    set_temp("apply/damage",500);
    set_skill("unarmed", 220);
    set_skill("force",180);
    set_skill("parry", 160);
    set_skill("dodge", 150);
    set_skill("changquan",220);
    set_skill("yue-spear",150);
    set_skill("manjianghong",150);
    set_skill("move", 180);
    set_skill("literate",140);
    set_skill("leadership",280);
    set_skill("strategy",280);
    set_skill("puti-steps",150);
    set_skill("spear",180);
    set_skill("perception", 200); 
    map_skill("unarmed","changquan");
    map_skill("dodge","puti-steps");
    map_skill("parry","yue-spear");
    map_skill("force","manjianghong");
    map_skill("spear","yue-spear"); 
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yuhuan" :),
        }) ); 
    setup();
    if(random(4)==2) set("env/no_teach",1);
    carry_object(__DIR__"obj/guanfu")->wear();
} 
int yuefei(){
        object me;
        me = this_player();
        if(me->query("marks/操练岳家中平枪法")){
                message_vision("$N对$n说道：“既然你已经去过大明湖畔，不妨去书库看看我的手稿。”\n", this_object(), me);
                return 1;
        }
        message_vision(CYN"\n$N对着$n长叹了一口气：“岳武穆当年的成名绝技［纵横天下］我也不能全部领悟\n"NOR,
                        this_object(), this_player());
        message_vision(CYN"中间的奥秘。 听说大明湖畔是他当年大破金军之处，你不妨去看看。”\n"NOR, this_object());
        this_player()->set("marks/大名湖畔纵横天下", 1);
        return 1;
}
void attempt_apprentice(object me)
{
    if( !me->query("class")||me->query("class")=="official")
    {
        if((int)me->query("combat_exp") > 400000 || me->query("m_success/头颅骨")) {
        command("smile");
        command("say 很好！朝廷正在用人之时，努力吧！\n");
        command("recruit " + me->query("id") );
        } else command("say 你什么都不会，也没有什么经验，怎么给朝廷效力？\n");
    }
    else command("say 朝廷不需要你这种不三不四，来历不明之人！\n");
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "official");
    ob->set("vendetta_mark", "authority"); 
}  
int accept_object(object who, object ob)
{
        if( ob->query("shangfang") ){
                this_object()->delete("env/no_teach");
        if(who->query_temp("marks/sword_gotit")) {
        //give reward
                command("nod");
                command("say 你真的是帮了我一件大忙，是个可以托付重任的人。\n");
                command("say 你再帮我查查是谁杀了当今武林武当派的老掌门？\n");
                if(!who->query("m_success/尚方宝剑")) {
                        who->set("m_success/尚方宝剑",1);
                        who->add("score",100);
                        tell_object(who,"好样的，你得到100点评价！\n");
                }
        } else {
        //punish
                command("ah");
                command("say 大胆！竟敢偷老夫的宝剑\n");
                kill_ob(who);
                }
        return 1;
        }
        if (ob->query("name")=="头颅骨" && ob->query("id")=="skull"
                && who->query("m_success/尚方宝剑"))    {
                command("ack");
                command("consider");
                command("say 看来武当派里蹊跷不少。\n");
                command("say 石雁城府很深，要解开这个谜需从他的弟子下手。特别是那个姓过的，当时老掌门病重时，就是他服伺的。\n");
                if(!who->query("m_success/头颅骨")) {
                        who->set("m_success/头颅骨",1);
                        who->add("score",100);
                        who->add("potential",900);
                        who->add("combat_exp",5000);
                        tell_object(who,"好样的，你得到100点评价，900点潜能，5000点经验！\n");
                }
                return 1;
        }
        return 0;
}  
void init()
{
        object ob;
        ::init();
        add_action("do_killing", "kill");
        if(interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, this_player());
        }
} 
void greeting(object ob) {
        if(!ob || environment(ob) != environment()) return;
        if (this_object()->query("env/no_teach")==1 && ob->query("family/master_id")=="master yin")
        message_vision("$N烦躁地说：“丢了尚方宝剑，老夫这会儿没心思教你。“\n",this_object());
}  
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "official"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N喝道：大胆草民，竟然敢在老夫面前撒野，欺朝廷无人么！\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        }
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="official") return 0;
        message_vision(CYN"$N正色道，“报效朝廷乃忠君爱民之事，怎么能半途而废呢。“\n"NOR, this_object());
        message_vision(CYN"$N说：若执意要走我也不勉强，只是从此就是一介平民，朝廷之事再也无权过问。\n"NOR,this_object());
        message_vision(CYN"$N说：玉环鸳鸯拳也不能再使，慎思，慎思。\n"NOR,this_object());
        return 1;
}   
