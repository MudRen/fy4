 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����", ({ "fengling" }) );
        set("gender", "����" );
        set("class", "bonze");
        set("title","�˹����·��ֱ���ʦ");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 29);
        set("int", 25);
        set("long", "�����˹����������������ķ��ֱ���ʦ\n");
        set("combat_exp", 60000);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������ռ���ɫ��ɫ���ǿգ�������\n",
        }) );
        set("inquiry", ([
                "·" : "��ȥ���յһ�����շ���ɡ�\n",
                "road" : "��ȥ���յһ�����շ���ɡ�\n",
        ]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}
int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
}  