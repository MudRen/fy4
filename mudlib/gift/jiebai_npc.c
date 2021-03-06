#include <ansi.h> 
inherit NPC; 
string jiebai();
string unjiebai(); 
void create()
{
    set_name("结拜测试人员", ({ "man" }) );
    set("gender", "男性" );
    set("age", 43);
    set("long",
        "一位精明能干的人\n");
    set("combat_exp", 10000);
    set("attitude", "friendly");
    set_skill("literate", 70);
    set_skill("dodge", 500);
    set_skill("unarmed", 300);
    setup();
    carry_object("/obj/armor/cloth")->wear(); 
    add_money("gold", 1);
} 
void init()
{
    ::init();
    add_action("do_jiebai", "jiebai"); 
    add_action("do_unjiebai", "divorce");
} 
int do_jiebai(string arg) 
{
    object obj, me;
    object ob;
    int i;
    string myclass,otherclass,location;
    me = this_player();
    
    location = environment(this_object())->query("short");
    
    if( me->query("jiebai"))
        write("你现在还有结拜的兄弟姐妹，不能再结拜其他人了。\n");
    else if(me->query("背信弃义"))
    	write("你如此没有信誉，还来结拜做什么？\n");
    else if(!arg || !objectp(obj = present(arg, environment(me))))
        write("你想和谁结拜？\n");
    else if(obj->query("背信弃义"))
    	write("对方是个背信弃义的小人，不值得你去结拜！\n");
    else if( obj->query("jiebai"))
        write("你的对象已经和别人结拜了。\n");
/*    else if((int)me->query("age")<16 && (string)me->query("gender")=="男性" ||
            (int)me->query("age")<14 && (string)me->query("gender")=="女性")
        write("你太小啦，怎么可以啦？\n");  */
    else if((myclass = me->query("class")) != "bonze" && myclass != "wudang" &&
            myclass != "lama" && myclass != "shaolin" && myclass != "taoist" &&
            myclass != "mei"  &&
            (otherclass = obj->query("class")) != "bonze" && myclass != "wudang" &&
            otherclass != "lama" && otherclass != "shaolin" && myclass != "taoist" &&
            otherclass != "mei" )
        write("这里现在规定，只有出家人才可以结拜。\n");
    else if( !living(obj) )
        write(obj->name() + "已经无法和你结拜了。\n");
    
    else if(obj==me)
        write("你难道要和自己结拜吗？太荒唐了吧！\n");
    else if(!userp(obj))
        write("你只可和玩家结拜．\n");
/*    else if((string)obj->query("gender")== (string)me->query("gender"))
        write("只能和同性结拜\n");   */                          //屏蔽只能和同性结拜
    else if( userp(obj) && !obj->query_temp(me->query("id") + "j"))
    {
        message_vision(MAG "\n$N对著$n说道：" 
                       + RANK_D->query_self(me) 
                       + me->name() + "，愿意和"
                       + RANK_D->query_respect(obj) + 
                       "结为金兰之交\n\n"NOR, me,obj);           
        me->set_temp(obj->query("id") + "j",1);
        tell_object(obj, MAG "如果你愿意和对方义结金兰，请你也对" 
                    +me->name() + "("+(string)me->query("id")+
                    ")"+ "下一次 jiebai 指令。\n"NOR);
    }
    else
    {
        me->set("jiebai",obj->query("id"));
        me->set("jiebai_name",obj->query("name"));
        obj->set("jiebai",me->query("id"));
        obj->set("jiebai_name",me->query("name"));
        
        message_vision(MAG "恭喜 $N 和 $n 在此义结金兰。\n"NOR,
                       obj, me);
        if(me->query("gender")=="男性")
            CHANNEL_D->do_sys_channel("info",sprintf(
                "%s,%s(%s)和%s(%s)在%s义结金兰，有福同享，有难同当！", 
                NATURE_D->game_time(),me->name(1),me->query("id"), 
                obj->name(1), obj->query("id"),location));
        else
            CHANNEL_D->do_sys_channel("info",sprintf(
                "%s,%s(%s)和%s(%s)在%s义结金兰，有福同享，有难同当！", 
                NATURE_D->game_time(),obj->name(1), obj->query("id"),
                me->name(1),me->query("id"),location));
    }
    return 1;
} 
int do_unjiebai(string arg)
{
    object jiebai_card1,jiebai_card2,  me;
    object couple_ob;
    int i, have_jiebai;
    string target, tmpstr1, tmpstr2,str1,str2;
    string cardname;
             
    me = this_player();       
    if (!me->query("jiebai"))  write("你未曾和任何人结拜。\n");
    else if(!objectp(couple_ob =
                present(target=(string)me->query("jiebai"), environment(me))))
        write("你结拜的人不在场.\n"); 
    else if( userp(couple_ob) && !couple_ob->query_temp(me->query("id")+"d"))
    {
        message_vision(MAG "\n$N对著$n说道：" + RANK_D->query_self(me) 
                       + me->name() + "，咱们解除结拜!互不干涉好吗?\n\n"
                      NOR, me, couple_ob);           
        me->set_temp(couple_ob->query("id")+"d",1);
        tell_object(couple_ob, MAG "如果你愿意解除结拜，请你也"
                    + "下一次 divorce 指令。\n"NOR);
//        write(MAG"现在你只有等着" +couple_ob->query("name")+"同意啦...\n"NOR);
    } else { 
        me->delete("jiebai");
        couple_ob->delete("jiebai");
        me->set("背信弃义",1);
        couple_ob->set("背信弃义",1);
        message_vision(MAG " $N 和 $n 从现在开始解除结拜关系，从此你走你的阳关道，我过我的独木桥！\n"NOR,
                       couple_ob, me);
        if(me->query("gender")=="男性")
            CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)和%s(%s)解除结拜关系，从此你走你的阳关道，我过我的独木桥！", me->name(1),
                me->query("id"),couple_ob->name(1),couple_ob->query("id")));
        else
            CHANNEL_D->do_sys_channel("info", sprintf(
                "%s(%s)和%s(%s)解除结拜关系，从此你走你的阳关道，我过我的独木桥！",couple_ob->name(1),
                couple_ob->query("id"),me->name(1),me->query("id")));
    }
    return 1;
} 
