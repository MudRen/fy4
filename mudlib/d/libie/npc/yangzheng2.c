#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("杨铮", ({ "yang zheng","yang","zheng" }) );
        set("long",
                "一个瘦削、黝黑、沉静，还不到三十岁的汉子，左臂齐肩而断。\n"); 
        set("attitude", "friendly");
        set("age",32);
        set("str", 80);
        set("cor",70);
        set("agi",50); 
        set("con",70);
        set("title", HIW"捕头"NOR); 
        set("combat_exp", 4000000+random(1000000));
        set("max_force",3000);
        set("force",3000);
         
        set_skill("unarmed",200);
        set_skill("sword",200);
        set_skill("libie-sword",200);
        set_skill("parry",1000);
        set_skill("dodge",200);
        set_skill("feixian-steps",200); 
        map_skill("sword","libie-sword");
        map_skill("dodge","feixian-steps");
/*
        set("chat_chance", 1);
        set("chat_msg", ({
"杨铮紧握双拳，愤怒的眼睛中似乎喷得出火来。”\n"
}) ); 
        set("inquiry", ([
                "劫镖案" : (: answer_robery :),
                "robery" : (: answer_robery :),
                "杨铮" : (: answer_yang :),
                "yang" : (: answer_yang :),
                "yang zheng" : (: answer_yang :),
                "狄青麟" : (: answer_di :),
                "di" : (: answer_di :),
                "di qinglin" : (: answer_di :),
        ])); 
*/
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/tieflag/obj/leavehook")->wield();
} 
/* 
int accept_object(object who, object ob)
{
        object hook,sword,me,room;
        
        me=this_object();
        room=environment();
        if(ob->query("name")!=MAG"离别钩"NOR) return 0;
        if(!present("di qinglin",room)) return 0;
        if(who->query_busy()) return 0;
        if(me->query_busy()) return 0;
        
        set_temp("送离别钩的人",who);
        hook=new("/d/tieflag/obj/leavehook");
        hook->move(me);
        if(sword=present("sword",me))
        if(sword->query("equipped"))
                command("unwield sword");
        command("wield leave hook");
        return 1;
}
        
*/
void heart_beat()
{
        object me,room,yang;
        int msg;
        
        yang=this_object();
        room=environment(); 
        if(msg=query("dying_msg"))
        {
                me=room->query("结局2人物");
                if(msg==5)
                   message_vision("$N呆呆的望着吕素文的尸体，竟没有注意到$n走了进来。\n",yang,me);
                if(msg==4) {
                        message_vision("$N呓语道：“素文。。我。。胜了。。从此再也没有谁能让我们再离别
了，就算是老天也不可以。。。。”\n",yang);
                        if(!me->query("imbue/libie")) {
                                this_object()->imbue_event(me);
                        }
                }
                if(msg==3)
                        message_vision("\n$N脸色忽然转为平静，缓缓举起了离别钩，忽然向自己心口插落，$n
大惊失色，正欲打算阻止，却为时已晚。\n",yang,me);
                if(msg==2)
                        message_vision("\n$N对$n微笑道：“杨某求仁得仁，此生已无憾，只盼"+RANK_D->query_respect(me)+"能将我夫妇二
人合葬在小木屋外黄土处。。\n",yang,me);
                if(msg==1)
                        {
                                message_vision("$N声音越来越小，慢慢的倒在了吕素文的身边。\n",yang);
                                me->set("libie/离别钩_尾声",1);
                                yang->die();
                        }
                add("dying_msg",-1);
        }
        ::heart_beat();
} 
void dying(object me)
{
        set("dying_msg",5);
}   
void die()
{       object me,corpse,*inv,room;
        int i; 
        room=environment();
        if(me=room->query("结局2人物"))
                me->delete_temp("离别钩_目睹最后结局");
        corpse=new("/d/libie/obj/yangcorpse2");
        corpse->move(room);
        inv=all_inventory(this_object());
        i=sizeof(inv);
        while(i--)
                inv[i]->move(corpse);
   message_vision("杨铮死了\n",this_object());
        destruct(this_object());
                
}
void imbue_event(object me){
        object weapon, ob, *inv, obj;
        string prop;
        int i;
        if(!interactive(me) || environment(me) != environment(this_object())) {
                return 0;
        }
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                                weapon = inv[i];
                                break;
                        }
                }       
        }
        if(!objectp(weapon)){
                if(!objectp(obj)) {
                        message_vision(HIR"\n滴答一声，一滴血泪落在$N身旁的地上。\n"NOR, me);
                } else {
                        message_vision(HIR"\n滴答一声，一滴血泪落在$N的" + obj->name() + HIR"上，又缓缓滑落到地上。\n"NOR,
                                        me);    
                }
        }else{
                message_vision(HIR"\n滴答一声，一滴血泪落在$N的" + weapon->name() + HIR"上。。。\n"NOR,
                                me);
                message_vision(HIR"红光乍现，" + weapon->name() + HIR"泛出夺目华晕，流转不停，稍倾又渐渐淡去。\n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
                        message_vision("$N不由自主松开了手中紧握的"+weapon->name()+"。\n", me);
           }
                if(me->query("宿命B/黄山_日出") ) {
                        weapon->add(prop+"courage", 5);
                        weapon->add(prop+"flexibility", 5);
                        weapon->add(prop+"agility", 5);
                        weapon->add(prop+"rigidity", 100);
                } else {
                        weapon->add(prop+"courage", 5);
                        weapon->add(prop+"rigidity", 50);
                }               
                weapon->save();
                me->set("imbue/libie", 1);
                me->save();
                return;
        }
        me->set("imbue/libie", 2);
        me->save();
        return;
}     
