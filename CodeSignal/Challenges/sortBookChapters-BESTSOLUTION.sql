CREATE FUNCTION fromRoman (inRoman varchar(15)) RETURNS INT
BEGIN

    DECLARE numeral CHAR(7) DEFAULT 'IVXLCDM';
    DECLARE digit TINYINT;
    DECLARE previous, current, sum INT DEFAULT 0;

    WHILE LENGTH(inRoman) > 0 DO
        SET digit = LOCATE(RIGHT(inRoman, 1), numeral) - 1;
        SET current = POW(10, FLOOR(digit / 2)) * POW(5, MOD(digit, 2));
        SET sum = sum + POW(-1, current < previous) * current;
        SET previous = current;
        SET inRoman = LEFT(inRoman, LENGTH(inRoman) - 1);
    END WHILE;

    RETURN sum;
END;

CREATE PROCEDURE sortBookChapters()
BEGIN
    DECLARE n, i, num_final INT DEFAULT 0;
    DECLARE num VARCHAR(15);

    START TRANSACTION;
    SELECT COUNT(*) FROM book_chapters INTO n;

    WHILE i < n DO
        SELECT UPPER(chapter_number)
        INTO num
        FROM book_chapters
        LIMIT i, 1;

        UPDATE book_chapters
        SET chapter_number = fromRoman(num)
        WHERE chapter_number = num;

        SET i = i + 1;
    END WHILE;

    SELECT chapter_name FROM book_chapters ORDER BY ABS(chapter_number);
    COMMIT;
END;
