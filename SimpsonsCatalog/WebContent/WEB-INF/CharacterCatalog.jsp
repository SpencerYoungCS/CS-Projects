<?xml version="1.0" encoding="ISO-8859-1" ?>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html lang="en">
<head>
<link rel="stylesheet"
	href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Simpson's Catalog</title>
</head>
<body>
	<div class="container">

		<div class="jumbotron text-center">
			<img style="width: 30%;"
				src="http://albertcervantes.com/cs3220/cdn/simpsons/simpsons.png">
			<h1>Character Catalog</h1>
			<p class="lead">Click on an image below to view a random image of
				your favorite character!</p>
		</div>
		<div class="row">
			<c:forEach items="${entries}" var="entry">
				<div class="col-sm-4 text-center">
					<div class="well">

						<a href="CharacterProfile?id=${entry.id}"> 
						<img
							style="height: 150px;"
							src="http://albertcervantes.com/cs3220/cdn/simpsons/${entry.noSpaceName}/pic_0001.jpg"
							onError="this.onerror=null;this.src='http://via.placeholder.com/150?text=N/A';"
							class="img-responsive img-thumbnail" alt="${entry.name}">
						<h4 class="text-center">${entry.name}</h4></a>
					</div>
				</div>
			</c:forEach>
		</div>
	</div>
</body>
</html>

