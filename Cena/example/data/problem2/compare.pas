uses
  libcheck;

var
  a,b,c,stc: string;

begin
  assign(input, '2.in'); { ����������ļ�������ȡ��׼���� }
  reset(input);
  readln(a);
  readln(b);
  close(input);
  assign(input, '2.out'); { ���������ļ�������ѡ�ֳ����������ȡѡ����� }
  reset(input);
  readln(c);
  close(input);
  read(std, stc); { �ӱ�׼����ļ��ж�ȡ��׼�� }

  writeln(rep, '������Ե������Ϊ��', a, ' ', b);
  writeln(rep, '��׼���Ϊ��', stc);
  writeln(rep, 'ѡ�����Ϊ��', c);
  if stc=c then begin
    writeln(rep, '��ȷ��');
    Score(fsco); { ������ }
  end
  else begin
    writeln(rep, '����');
    Score(0); { �� 0 �� }
  end;
  writeln(rep, '��У������� *** �ṩ������ʾ����');
  Finish;
end.