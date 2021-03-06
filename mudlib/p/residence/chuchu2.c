 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 15
#define Y_COOR 2039
#define Z_COOR 50
#define R_FLAG 30
#define OWNER "chuchu"
#define CLASS "白云城"
inherit ROOM;
void create()
{
set("short", HIG"客厅"NOR);
set("long", @LONG
厅子不大，中央是一张红木桌(Table)，桌子旁边摆了两张椅子，看起来这顿饭
只是楚楚和唠叨两个人吃。桌上只有两个空碟、两副筷子和一个不知装着什么的大
铁盆。

LONG
);
        set("exits", ([
		"north" : __DIR__"chuchu6",
		"south" : __DIR__"chuchu1",
		"west" : __DIR__"chuchu4",
		"east" : __DIR__"chuchu3",
	]));

        set("item_desc", ([
        	"table": "一张红木制成的八仙桌，上面有一大盆水煮鱼（boiled fish）。\n",
        	"桌子": "一张红木制成的八仙桌，上面有一大盆水煮鱼（boiled fish）。\n",
        ]) );

        set("coor/x",X_COOR);
   	set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        set("indoors","residence");
        setup();
}
void init()
{
        int flag;
        flag = (int) query("room_flag");
        if(flag & 1) set("valid_startroom",1);
        if(flag & 2) set("NONPC",1);
        if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
        if(flag & 16) set("indoors","residence");
        add_action("do_invite","invite");
        add_action("do_setowner","setowner");
        add_action("do_list","list");
        add_action("do_eat","eat");
}

int do_eat(string arg)
{
	if(arg=="boiled fish" || arg=="水煮鱼")
	{
		message_vision(HIC"$N被辣得“啊”的一声跳了起来，头“乒”的一声撞上了房梁，然后重重的摔了", this_player());
		message_vision("下来，但$N并不觉得疼，\n因为。。。。。。", this_player());
		message_vision("$N已经被水煮鱼里的花椒麻翻了:P\n"NOR, this_player());
	return 1;
	}
	write("你想吃什么？\n");
	return 1;
}


int valid_enter(object me)
{
        int flag;
// means no enter at the beginning.
        int enter = 0;
    flag = (int) query("room_flag");
// always let owner go in:
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 16)
        enter = 1;
        if(flag & 512)
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 1024)
        if((string)me->query("class") == (string)query("class"))
        enter = 1;
        if(flag & 2048) 
        {
                if(strlen(query("invite")) && strsrch((string)query("invite"),"["+(string)me->query("id")+"]") != -1)
           enter = 1;
        }
//      write(sprintf("%d", enter));    
        return enter;
}
int do_list()
{
        object me;
        string *list,invitelist;
        me = this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        invitelist = query("invite");
        if (strlen(invitelist))
        {
                list = explode("]"+invitelist+"[", "][");
                write("你邀请了下列玩家到你的房间:\n");
                for(int i=0;i<sizeof(list);i++)
                        write(list[i]+"\n");
        }else
                write("你没有邀请任何人到你的房间。\n");
        return 1;
} 
int do_invite(string arg)
{
        object me;
        string invitelist;
        me= this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        if( !arg )
        {
                write("你要邀请谁? \n");
                return 1;
        }
        invitelist = (string)query("invite");
        if(strlen(invitelist) && strsrch(invitelist,"["+arg+"]") != -1)
        {
                //if the person has already been invited, remove it from invite list.
                invitelist = replace_string(invitelist,"["+arg+"]","");
           set("invite",invitelist);
                write("你将"+arg+"从你的邀请名单中除去。\n");
        }else
        {
                //invite the person.
                if( find_player(arg))
                {
                        if(!strlen(invitelist))
                                set("invite","["+arg+"]");
                        else
                                set("invite",invitelist+"["+arg+"]");
                        write("你邀请"+arg+"来你的房间。\n");
                }else
                {
                        write("咦... 有这个人吗?\n");
                }
        }
        return 1;
} 
int do_setowner(string arg)
{
        string oldowner;
        oldowner = (string)query("owner");
        set("owner",arg);
        write("你将房间的主人暂时设为"+arg+"。\n");
        call_out("set_back",60, oldowner);
        return 1;
} 
int set_back(string oldowner)
{
        set("owner", oldowner);
        return 1;
}
    
