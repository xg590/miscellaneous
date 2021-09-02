function FindProxyForURL(url, host) { 
  
  // Hostname matches 
  if (
     shExpMatch(host, "(*.adorcam.com|*.wikipedia.org)") 
  )
  return "PROXY 192.168.3.3:8080"; 
  
  // Default rule: All other traffic, use below proxies, in fail-over order. 
  return "DIRECT";
  
}
