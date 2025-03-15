FROM gcc:latest

WORKDIR /app

COPY . /app

RUN g++ -o calc test.cpp

CMD ["./calc"]