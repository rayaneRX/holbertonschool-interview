def pascal_triangle(n):
    if n <= 0:
        return []

    # Initialize the triangle with the first row
    triangle = [[1]]

    # Generate each row
    for i in range(1, n):
        # Start each row with a 1
        row = [1]
        
        # Compute the values in the middle of the row
        for j in range(1, i):
            row.append(triangle[i-1][j-1] + triangle[i-1][j])
        
        # End each row with a 1
        row.append(1)
        triangle.append(row)
    
    return triangle
