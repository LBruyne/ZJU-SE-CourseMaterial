public static List<String> convertStringToList(String line) 
    {
    	String[] ss = line.split("\\s+");//String的split方法支持正则表达式
    	List<String> list = new ArrayList<String>(Arrays.asList(ss));//将数组转化为list
    	return list;
    }
    public static void remove(List<String> list, String str)
    {
    		if(!list.contains(str))
    			return;
    		else
    		{
    			for(int i = 0;i < list.size();i++)
    			{
    				if(str.contains(list.get(i)))
    				{
    					list.remove(list.get(i));
    					i--;//这是难度，删除的话必须加这句，否则你可能会出现跳着删除的情况，如样例一
    				}
    					
    			}
    		}
    }