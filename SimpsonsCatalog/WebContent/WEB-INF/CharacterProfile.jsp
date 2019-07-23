<?xml version="1.0" encoding="ISO-8859-1" ?>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>

<!DOCTYPE html>
<html lang="en">
<form action="CharacterProfile" method="get">
	<head>
<link rel="stylesheet"
	href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css"
	integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u"
	crossorigin="anonymous">
<link rel="stylesheet" href="../css/simpsons.css">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>${entry.name}'s Profile</title>
	</head>
	<body>

		<div class="container">
			<div class="row">
				<div class="col-sm-offset-3 col-sm-6">
					<div class="well text-center">
						<img style="width: 30%;"
							src="http://albertcervantes.com/cs3220/cdn/simpsons/simpsons.png">
						<h2>${entry.name}</h2>
						<p class="lead">Displaying 1 of ${entry.numOfPictures} images.</p>
						<p>
							<a class="btn btn-success" href="CharacterCatalog"> Catalog </a>
							<a class="btn btn-success" href="CharacterProfile?id=${entry.id}">
								Next Image </a>
						</p>
						<p class="text-center" style="overflow: none;">
							<a href="CharacterProfile?id=${entry.id}"> <img
								style="max-height: 200px;"
								src="http://albertcervantes.com/cs3220/cdn/simpsons/${entry.noSpaceName}/pic_${randomNum2}.jpg"></a>
						</p>

					</div>
				</div>
			</div>
		</div>
	</body>

</form>
</html>