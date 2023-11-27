//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;


class GFG{
    static class FastReader{ 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader(){ 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next(){ 
            while (st == null || !st.hasMoreElements()){ 
                try{ st = new StringTokenizer(br.readLine()); } catch (IOException  e){ e.printStackTrace(); } 
            } 
            return st.nextToken(); 
        } 
  
        String nextLine(){ 
            String str = ""; 
            try{ str = br.readLine(); } catch (IOException e) { e.printStackTrace(); } 
            return str; 
        } 

        Integer nextInt(){
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) throws IOException
    {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = sc.nextInt();
        while(t-- > 0){
            int N = sc.nextInt(), K = sc.nextInt();
            Solution ob = new Solution();
            String ans = ob.findString(N, K);
            boolean ok = true;
            for(int i = 0; i < ans.length(); i++){
                char c = ans.charAt(i);
                if(c < '0' || c > K - 1 + '0')
                    ok = false;
            }
            if(!ok){
                out.println("-1");
                continue;
            }
            HashSet<String> st = new HashSet<String>();
            for(int i = 0; i + N - 1 < ans.length(); i++){
                st.add(ans.substring(i, i+N));
            }
            int tot = 1;
            for(int i=1;i<=N;i++)
                tot *= K;

            if(st.size() == tot){
                out.println(ans.length());
            }
            else{
                out.println("-1");
            }
        }
        out.flush();
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    public boolean dfs(int n, int k, int total_possibilities, StringBuilder path, Set<String> visited){
        if(visited.size() == total_possibilities){
            return true;
        }
        for(int i = 0; i < k; i++){
            String curr_node = path.substring(path.length() - n + 1);
            curr_node += (char)('0' + i);
            if(!visited.contains(curr_node)){
                visited.add(curr_node);
                path.append((char)('0' + i));
                if(dfs(n, k, total_possibilities, path, visited)){
                    return true;
                }
                path.deleteCharAt(path.length() - 1);
                visited.remove(curr_node);
            }
        }
        return false;
    }
    public String findString(int n, int k){
       StringBuilder path = new StringBuilder();
        for(int i = 0; i < n - 1; i++){
            path.append('0');
        }
        Set<String> visited = new HashSet<>();
        int total_possibilities = (int)Math.pow(k, n);
        dfs(n, k, total_possibilities, path, visited);
        return path.toString();
       
    }
}
