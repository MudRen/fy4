#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
int kill_him(); 
void create()
{ 
        set_name("柳东来",({"liu donglai","liu","donglai"}));
        set("title",YEL"护花剑客"NOR);
        set("long", "一个很体面的中年人，穿着很考究，须发虽已发白，看来却还是风度翩翩，很能吸
引女人。他的手也保养得很好，手指修长、干燥、有力，不但适于握刀剑，也适于发
暗器。\n");
        set("age",59);
        set("combat_exp", 6400000);
        set("attitude", "friendly");
        
        set("inquiry", ([
             "白天羽" : (: kill_him :),
        ]));
        set("no_busy",9);
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",300); 
        
                set("reward_npc", 1);
        set("difficulty", 20);
        
    set_skill("move", 120);
    set_skill("parry",150);
    set_skill("dodge", 120);
    set_skill("force", 280);
    set_skill("literate", 180);
    set_skill("unarmed",220);
    set_skill("sword",450);

    set_skill("jindian-fire",200);
    set_skill("hanshan-sword",180);
    set_skill("wuchen-steps",200);
    set_skill("wuchenforce",220);

    map_skill("dodge", "wuchen-steps");
    map_skill("move", "wuchen-steps");
    map_skill("force", "wuchenforce");
    map_skill("unarmed", "jindian-fire");
    map_skill("sword","hanshan-sword");
    map_skill("parry","jindian-fire");

        
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        set("class","quanli");
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//         defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                             (: perform_action, "sword.yueyinghanshan" :),
        }) );
         
        CHAR_D->setup_char(this_object());
      //  auto_npc_setup("xuebin",250,180,1,"/obj/weapon/","fighter_w","softsword");
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}  
void init()
{
        add_action("do_killing", "kill");
        ::init();
} 
int kill_him()
{
        object me, another;

        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"柳东来现在没空回答你。\n");
                return 1;
                }
                        
        message_vision(CYN"$N道：“那次我们做的事，虽然不够光明磊落，但现在若回到十九年前，我
还是会再同样做的。。。。因为白天羽实在不是个东西。不错，是为了个女人，她
叫做洁如，她本来是我的，但是白天羽却用他的权势和钱财，强占了她！”\n"NOR,this_object());
        if( me->query_temp("killed_yuan_ma"))
        {
         message_vision("\n\n\n$N长叹一声，「所以，当晚参与的人，是我。你，杀，错，人，了！」\n\n"NOR,this_object());
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        }
        return 1;

}
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/柳东来_ma", 1);
        }
        
        ::die(); 

}
int do_killing(string arg)
{
        
        object player, victim, weapon;
        string name;
        player = this_player();
        if( !arg) return 0;
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = (string)victim->name();
                if( (string)name == "袁秋云")
                {
                message_vision("$N一把挡在袁秋云身前：「不需忌讳，速战速决！」\n", this_object());
                this_object()->kill_ob(player);
                player->kill_ob(this_object());
                return 0;
                }
        }
        return 0;               
} 