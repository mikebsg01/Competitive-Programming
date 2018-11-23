CREATE FUNCTION decimalValue(c CHAR) RETURNS INT
BEGIN 
  DECLARE d INT DEFAULT 0;
  SET d = d + IF(c = 'I',1,0);
  SET d = d + IF(c = 'V',5,0);
  SET d = d + IF(c = 'X',10,0);
  SET d = d + IF(c = 'L',50,0);
  SET d = d + IF(c = 'C',100,0);
  SET d = d + IF(c = 'D',500,0);
  SET d = d + IF(c = 'M',1000,0);
  RETURN d;
END;

CREATE PROCEDURE sortBookChapters()
BEGIN
    DECLARE n, len, i, j, s1, s2, num_final INT DEFAULT 0;
    DECLARE num, num_char varchar(15);
    
    START TRANSACTION;
    SELECT COUNT(*) FROM book_chapters INTO n;

    WHILE i < n DO
        SELECT LENGTH(chapter_number), UPPER(chapter_number)
        INTO len, num
        FROM book_chapters
        LIMIT i, 1;

        SET j = 1;
        SET num_final = 0;

        WHILE j <= len DO
            SELECT SUBSTRING(chapter_number, j, 1)
            INTO num_char
            FROM book_chapters
            LIMIT i, 1;

            SET s1 = decimalValue(num_char);

            IF j+1 <= len THEN
              SELECT SUBSTRING(chapter_number, j+1, 1)
              INTO num_char
              FROM book_chapters
              LIMIT i, 1;

              SET s2 = decimalValue(num_char);

              IF s1 >= s2 THEN
                SET num_final = num_final + s1;
              ELSE
                SET num_final = num_final + s2 - s1;
                SET j = j + 1;
              END IF;
            ELSE 
              SET num_final = num_final + s1;
            END IF;

            SET j = j + 1;
        END WHILE;

        UPDATE book_chapters
        SET chapter_number = CAST(num_final AS CHAR)
        WHERE chapter_number = num;

        SET i = i + 1;
    END WHILE;

    SELECT chapter_name FROM book_chapters ORDER BY ABS(chapter_number);
    COMMIT;
END
