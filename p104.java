import java.math.BigInteger;
import java.io.InputStream;

public class test{   
public static void main(String[] args)throws Exception   
{   
	BigInteger a = new BigInteger("1");
	BigInteger b = new BigInteger("1");
	int cnt1 = 2479;
	int cnt2 = 3;
	int s[] = new int[10];
	while(true)
	{
		if(cnt2>cnt1)
		{
			String k = b.mod(new BigInteger("1000000000")).toString();
			if(k.length()==9)
			{
				Boolean flag = true;
				for(int i=1;i<=9;i++)s[i]=0;
				for(int i=1;i<=9;i++)
				{
					if(k.charAt(i-1)-48==0)
					{
						flag = false;
						break;
					}
					if(s[k.charAt(i-1)-48]==0)s[k.charAt(i-1)-48]=1;
					else
					{
						flag = false;
						break;
					}
				}
				if(flag==true)
				{
					System.out.println(cnt2-1);
					BigInteger div = new BigInteger("10").pow(b.toString().length()-9);
					String kk = b.divide(div).toString();
					if(kk.length()==9)
					{
						Boolean f = true;
						for(int i=1;i<=9;i++)s[i]=0;
						for(int i=1;i<=9;i++)
						{
							if(kk.charAt(i-1)-48==0)
							{
								f = false;
								break;
							}
							if(s[kk.charAt(i-1)-48]==0)s[kk.charAt(i-1)-48]=1;
							else
							{
								f = false;
								break;
							}
						}
						if(f==true)
						{
							System.out.println(cnt2-1);
							break;
						}
					}
				}
			}
		}
		BigInteger c = a.add(b);
		a = b;
		b = c;
		cnt2++;

	}
	
    
}   
}  