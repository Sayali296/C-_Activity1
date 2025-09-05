# Node Base Image
FROM node:12.2.0-alpine

#Working Directry
WORKDIR /node

#Copy the Code
COPY . .

#Install the dependecies
EXPOSE 8000

#Run the code
CMD ["node","app.js"]
