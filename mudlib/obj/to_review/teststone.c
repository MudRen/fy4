 inherit ITEM;
void create()
{
        set_name("魔像" , ({ "powerstatus" }) );
        set_weight(600);
        set("unit", "块");
        set("value",100);
        set("no_get",1);
        set("long", "这好象就是阿铁吗！
如果想恢复初始状态，请 setdefault
如果想要基本武功，请 setbasic
如果想要清判师，请 setclear
");
        ::init_item();
} 
void init()
{
        add_action("setdefaults", "setdefault");
        add_action("setbasics", "setbasic");
        add_action("setclears", "setclear");
        add_action("setdefaults2","setdefault2");
}
int setclears()
{
this_player()->delete("betrayer");
this_player()->delete("family");
this_player()->delete("class");
message_vision("$N很开心！！\n",this_player());
write("ok\n");
return 1;
}
int setbasics()
{
object me;
me = this_player();
me->set_skill("force",70);
me->set_skill("literate",70);
me->set_skill("dodge",70);
me->set_skill("move",70);
me->set_skill("parry",70);
me->set_skill("unarmed",70);
me->set_skill("sword",70);
me->set_skill("blade",70);
me->set_skill("unarmed",70);
me->set_skill("hammer",70);
me->set_skill("staff",70);
me->set_skill("whip",70);  
me->save();
write("ok\n");
return 1;
}
int setdefaults()
{
object me;
me=this_player();
if(me->query("combat_exp") > 500000)
return notify_fail("你的经验高过初始状态，如果你要恢复初始状态请输入setdefault2\n");
me->set("combat_exp",500000);
me->set("deposit",1000000);
me->set("max_force",200);
me->set("score",3000);
me->set("potential",10000);
me->save();
write("ok\n");
return 1;
}
int setdefaults2()
{
object me;
me=this_player();
me->set("combat_exp",500000);
me->set("deposit",1000000);
me->set("max_force",200);
me->set("score",3000);
me->set("potential",10000);
me->save();
write("ok\n");
return 1;
}      
