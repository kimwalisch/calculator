pipeline {
    agent any

    stages {
        stage('Clone Repository') {
            steps {
                git branch: 'master', url: 'https://github.com/vitrubnikova/calculator-test-for-pvs.git'
            }
        }
        stage('Build Docker Image') {
            steps {
                script {
                    // Указываем имя образа
                    dockerImage = docker.build("calc:${env.BUILD_ID}")
                }
            }
        }
    }

    post {
        success {
            emailext (
                subject: 'SUCCESS: Job ${env.JOB_NAME}',
                body: 'Build успешно завершен!',
                to: 'vitrubnikova@gmail.com'
            )
        }
        failure {
            emailext (
                subject: 'FAILURE: Job ${env.JOB_NAME}',
                body: 'Build завершился с ошибкой!',
                to: 'vitrubnikova@gmail.com'
            )
        }
    }
