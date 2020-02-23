<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" >

<head><title>PHP Testing-1</title></head>
<body>
<div align="center">
<table border="0" bgcolor="#CCFFFF" width="70%">
    <?php
        $SIP="155.69.100.36";
		$TMsg="PHP Testing - Successful!";
		$CSC="CSC302/CZ3006 Net Centric Computing";
	?>
	
	<tr><td align="center">
	<fond style="font-size:30pt;color:#FF0000;font-weight:bold;">
	<u>CZ3006 Web Server</u>
	</fond></td></tr>

	<tr><td align="center">
	<fond style="font-size:22pt;color:#0000FF;font-weight:bold;">
	Server IP Address = <?php echo "$SIP" ?> 
	</fond></td></tr>

	
	<tr><td align="center">
	<fond style="font-size:20pt;color:#0000FF;font-weight:bold;">
	<a href="<?php echo "$CSC" ?>" target="CSCFAQ"> <?php echo "$CSC" ?> </a>	
	</fond></td></tr>

	<tr><td align="center" height="90">
	<fond style="font-size:28pt;color:#00FF00;font-weight:bold;"><blink> <?php echo "$TMsg" ?> </blink></fond>
	</td></tr>
	
</table></div></body></html>
