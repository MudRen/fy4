 // post_officer.c
inherit NPC; 
string send_mail();
string receive_mail(); 
void create()
{
        set_name("王风", ({ "officer", "post officer" }) );
        set("title", "风云绎驿长");
        set("gender", "男性" );
        set("age", 43);
        set("long",
                "王风担任风云驿的驿长已经有几年了，人很好，\n"
                "居民对王风的风评相当不错，常常会来到驿站跟他聊天。\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set("inquiry", ([
                "驿站" : "是啊... 这里就是风云绎，你要寄信或租马车吗？",
                "寄信" : (: send_mail :),
                "收信" : (: receive_mail :),
                "mail" : (: receive_mail :),
        ]) );
        set_skill("literate", 70);
        set_skill("unarmed", 400);
        setup();
        add_money("coin", 70);
        carry_object("/obj/armor/cloth")->wear();
} 
void init()
{       
        ::init();
        add_action("do_rent","rent");
} 
string send_mail()
{
        object mbox; 
        if( this_player()->query_temp("mbox_ob") )
                return "你的信箱还在吧？用信箱就可以寄信了。\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "真是抱歉，请您等一下到驿站来找我吧。\n";
   seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "哦... 要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
} 
string receive_mail()
{
        object mbox; 
        if( this_player()->query_temp("mbox_ob") )
                return "你的信箱还在吧？你所有的信都在里面。\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "真是抱歉，请您等一下到驿站来找我吧。\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
} 
int do_rent(string arg)
{ 
        object ob, chefu;
        object me = this_player();
        object silver;
        if (arg != "carriage" && arg != "mache")
        {
                return notify_fail("你要租什么？\n");
        } 
        if (query("mark/rented"))
        {
                return notify_fail("马车已经租出去了 \n");
        }
        silver=present("silver_money", me);
    if(!silver) return notify_fail("你身上没有银子呀。\n");
        if (silver->query_amount()<8) return notify_fail("你的钱不够。\n");
    silver->add_amount(-8); 
        ob=new(__DIR__"obj/carriage");
    ob->move(environment());
        message_vision("$N驶了过来 \n",ob); 
    chefu=new(__DIR__"chefu");
    chefu->move(environment());
    chefu->get_quest("/d/fy/carriageway");
    chefu->set_carriage(ob);
        message_vision("$N走了过来 \n",chefu); 
        set("mark/rented",1);
        message_vision("$N打开马车门，坐进了马车 \n",me);
        me->move(ob);
        chefu->go_now();
        
        call_out("check_status",30,chefu);
        return 1;
} 
int check_status(object ob)
{
        if (!ob)
        {
                set("mark/rented",0);
        }else
        {
                call_out("check_status",30,ob);
        }
}   
