<?php
	$username = $_POST["userName"];
	$appleQty = intval($_POST["apple_Qty"]);
	$orangeQty = intval($_POST["orange_Qty"]);
	$bananaQty = intval($_POST["banana_Qty"]);
	$totalPrice = floatval(str_replace("$", "", $_POST["total_Cost"]));	//remove "$"
	$paymentType = $_POST["payment"];

	$filename = "order.txt";

	if(!file_exists($filename))
	{
		//create file if it doesn't exist
		$fd = fopen($filename, "w");
		fclose($fd);
	}

	//check if it is empty
	$filesize = filesize($filename);

	//check if file is empty
	if($filesize == 0)
	{
		//write fresh content to file
		$fd = fopen($filename, "w");
		fwrite($fd, "Total number of apples: $appleQty\nTotal number of oranges: $orangeQty\nTotal number of bananas: $bananaQty");
	}
	else
	{
		$fd = fopen($filename, "r");

		//split orders into list of order strings
		$orderList = explode("\n", fread($fd, $filesize));

		//get total order quantity from database("order.txt")
		$appleQty_total = intval(explode(": ", $orderList[0])[1]);
		$orangeQty_total = intval(explode(": ", $orderList[1])[1]);
		$bananaQty_total = intval(explode(": ", $orderList[2])[1]);

		//add with new order quantities
		$appleQty_total += $appleQty;
		$orangeQty_total += $orangeQty;
		$bananaQty_total += $bananaQty;

		//pop out of memory
		fclose($fd);
		$fd = fopen($filename, "w");
		fwrite($fd, "Total number of apples: $appleQty_total\nTotal number of oranges: $orangeQty_total\nTotal number of bananas: $bananaQty_total");
	}

	fclose($fd);

	echo 
	'
	<!DOCTYPE html>
	<html>
	<head>
		<title>CZ3006 Webpage Project</title>
		<meta charset="utf-8">
		<link href="css/bootstrap.min.css" rel="stylesheet">
	</head>
	<body>
	<div class="container" style="margin-top: 75px;">
		<table class="table table-borded table-striped">
			<tr><center><h1>Receipt<h1/></center></tr>
			<tr>
				<td>Customer: </td>
				<td>'.$username.'</td>
			</tr>
			<tr>
				<td>Apples: </td>
				<td>'.$appleQty.'</td>
			</tr>
			<tr>
				<td>Oranges: </td>
				<td>'.$orangeQty.'</td>
			</tr>
			<tr>
				<td>Bananas: </td>
				<td>'.$bananaQty.'</td>
			</tr>
			<tr>
				<td>Total Price: </td>
				<td>$'.$totalPrice.'</td>
			</tr>
			<tr>
				<td>Payment Price: </td>
				<td>'.$paymentType.'</td>
			</tr>
		</table>
		<div style="text-align: center;">
			<button type="button" class="btn btn-primary" style="width: 200px; height: 50px;" text onclick="goBackHome()">Home</button>
		</div>
	</div>
	</body>
	<script>
		function goBackHome()
		{
			location.replace("index.html");
		}
	</script>
	</html>
	'
?>