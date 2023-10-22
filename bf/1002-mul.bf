++++[>++++[>+++<-]<-]   writing 48 => '0' in cell(2), runs 4 * 12
    ,>,>                    read two int frm stdn in cell(0) and cell(1)
    [<-<->>-]               decrements cell(0) & cell(1) by '0'
    <<                      go to cell(0)
    [                       multiplication loop
        >                   go to cell(1)
        [>+>+<<-]           move cell(1) to cell(2) and cell(3)
        >>                  go to cell(3)
        [<<+>>-]            move cell(3) back to cell(1)
        <<<-                decrement cell(0)
    ]
    >[-]<                   set cell(1) to 0 so that it can be used as counter
    ++++[>++++[>+++<-]<-]   adding 48 / 0x30 / '0' to cell(2)
    >>.                     print result
